#include"header.h"
#include<stdio.h>
#include<stdlib.h>
#include <ctype.h>

extern int yyerror(char const *);
struct loop_label_node *loop_head=NULL;

int get_register(){
    if(REG_COUNT>20){
        printf("Out of Registers!\n");
        exit(1);
    }
    else 
        return REG_COUNT++;
}

void free_register(){
    if(REG_COUNT<0){
        printf("Register error!(count negative)\n");
        exit(1);
    }
    else
        REG_COUNT--;
}

int next_label(){
    return LABEL_COUNT++;
}

void push_to_LL(int brk,int cnt){
    struct loop_label_node *temp= (struct loop_label_node *)malloc(sizeof(struct loop_label_node));
    temp->brk= brk;
    temp->cnt= cnt;
    temp->next= loop_head;
}

void pop_from_LL(){
    if(loop_head==NULL) return ;
    struct loop_label_node*temp= loop_head;
    loop_head= loop_head->next;
    free(temp);
}

struct tnode * createTree(int val,  enum VarType type, char varname, enum NodeType nodetype, struct tnode* left, struct tnode* mid, struct tnode* right){
    struct tnode* temp;
    temp= (struct tnode*)malloc(sizeof(struct tnode));
    temp->val= val;
    temp->type= type;
    temp->nodetype= nodetype;
    
    if(isalpha(varname)) temp->varname= varname;
    else temp->varname='\0';

    temp->left=left;
    temp->mid= mid;
    temp->right=right;

    if(type_guard(temp))
        return temp;
    else {
        printf("Now exiting\n");
        exit(1);
    }
}

int evaluate(struct tnode* t){
    int l,r, m;
    if(t==NULL){
        return -1;
    }
    switch(t->nodetype){
        case _ID:
            return variable_array[t->varname -'a'];
        case _NUM:
            return t->val;
        
        case _PLUS :
            return evaluate(t->left)+ evaluate(t->right);
        case _MINUS :
            return evaluate(t->left)- evaluate(t->right);
        case _MUL :
            return evaluate(t->left)* evaluate(t->right);
        case _DIV :
            return evaluate(t->left)/ evaluate(t->right);
        case _LT :
            return evaluate(t->left)< evaluate(t->right);
        case _GT :
            return evaluate(t->left)> evaluate(t->right);
        case _EQ :
            return evaluate(t->left)== evaluate(t->right);
        case _GE :
            return evaluate(t->left)>= evaluate(t->right);
        case _LE :
            return evaluate(t->left)<= evaluate(t->right);
        case _NE :
            return evaluate(t->left)!= evaluate(t->right);
        
        case _CONNECTOR :
            evaluate(t->left);
            evaluate(t->right);
            return -1;
        
        case _ASSIGN :
            variable_array[ (t->left->varname) -'a']= evaluate(t->right);
            return variable_array[(t->left->varname) -'a'];
        
        case _READ :
            return scanf("%d",&variable_array[(t->left->varname)-'a']);
        case _WRITE :
			return printf("%d\n",evaluate(t->left));
        
        case _IF_THEN_ELSE :
            if(evaluate(t->left)){
                return evaluate(t->mid);
            }
            else 
                return evaluate(t->right);
        
        case _IF_THEN :
            if(evaluate(t->left)){
                return evaluate(t->mid);
            }
            else return -1;
        
        case _WHILE:
            while(evaluate(t->left)){
                evaluate(t->mid);
            }
            return -1;
        
        case _DO_WHILE :
            do{
                evaluate(t->mid);
            }while(t->left);
            return -1;
        
        case _REAPEAT_UNTIL :
            do{
                evaluate(t->mid);
            }while(! evaluate(t->left));
            return -1;

    }
}

int codeGen(struct tnode* t){
    int l ,r, m, _else, _endif, reg1, reg2, location, _while_start,_while_end;

    if(t== NULL) return -1;

    switch(t->nodetype){
        case _NUM:
            reg1= get_register();
            fprintf(target_file,"MOV R%d, %d\n",reg1, t->val);
            return reg1;

        case _ID:
            reg1= get_register();
            location= STACK_START + (t->varname)-'a';
            fprintf(target_file, "MOV R%d,[%d]\n", reg1, location);
            return reg1;

        case _ASSIGN:
			r = codeGen(t->right);
			location = STACK_START+ (t->left->varname) - 'a';
			fprintf(target_file,"MOV [%d], R%d\n", location, r);
			free_register();
			return r;
            
        case _PLUS:
            l= codeGen(t->left);
            r= codeGen(t->right);
            fprintf(target_file,"ADD R%d,R%d\n",l, r);
            free_register();
            return l;
        case _MINUS:
            l= codeGen(t->left);
            r= codeGen(t->right);
            fprintf(target_file,"SUB R%d,R%d\n",l, r);
            free_register();
            return l;
        case _DIV:
            l= codeGen(t->left);
            r= codeGen(t->right);
            fprintf(target_file,"MUL R%d,R%d\n",l, r);
            free_register();
            return l;
        case _MUL:
            l= codeGen(t->left);
            r= codeGen(t->right);
            fprintf(target_file,"DIV R%d,R%d\n",l, r);
            free_register();
            return l;
        case _LT:
            l= codeGen(t->left);
            r= codeGen(t->right);
            fprintf(target_file,"LT R%d,R%d\n",l, r);
            free_register();
            return l;
        case _GT:
            l= codeGen(t->left);
            r= codeGen(t->right);
            fprintf(target_file,"GT R%d,R%d\n",l, r);
            free_register();
            return l;
        case _LE:
            l= codeGen(t->left);
            r= codeGen(t->right);
            fprintf(target_file,"LE R%d,R%d\n",l, r);
            free_register();
            return l;
        case _GE:
            l= codeGen(t->left);
            r= codeGen(t->right);
            fprintf(target_file,"GE R%d,R%d\n",l, r);
            free_register();
            return l;
        case _EQ:
            l= codeGen(t->left);
            r= codeGen(t->right);
            fprintf(target_file,"EQ R%d,R%d\n",l, r);
            free_register();
            return l;
        case _NE:
            l= codeGen(t->left);
            r= codeGen(t->right);
            fprintf(target_file,"NE R%d,R%d\n",l, r);
            free_register();
            return l;
        
        case _CONNECTOR:
            l= codeGen(t->left);
            r= codeGen(t->right);
            return -1;

        case _READ:
			reg1 = get_register();
            location= STACK_START+ (t->left->varname)-'a';
			fprintf(target_file,"MOV R%d, \"Read\"\n",reg1);
			fprintf(target_file,"PUSH R%d\n",reg1);
			fprintf(target_file,"MOV R%d, -1\n",reg1);
			fprintf(target_file,"PUSH R%d\n",reg1);
			fprintf(target_file,"MOV R%d, %d\n",reg1, location);
			fprintf(target_file,"PUSH R%d\n",reg1);
			fprintf(target_file,"PUSH R%d\n",reg1);
			fprintf(target_file,"PUSH R%d\n",reg1);
			fprintf(target_file,"CALL 0\n");
			fprintf(target_file,"POP R%d\n",reg1);
			fprintf(target_file,"POP R%d\n",reg1);
			fprintf(target_file,"POP R%d\n",reg1);
			fprintf(target_file,"POP R%d\n",reg1);
			fprintf(target_file,"POP R%d\n",reg1);
			free_register();
			return -1;

		case _WRITE:
			l = codeGen(t->left);
			reg1 = get_register();
			fprintf(target_file,"MOV R%d, \"Write\"\n",reg1);
			fprintf(target_file,"PUSH R%d\n",reg1);
			fprintf(target_file,"MOV R%d, -2\n",reg1);
			fprintf(target_file,"PUSH R%d\n",reg1);
			fprintf(target_file,"PUSH R%d\n",l);
			fprintf(target_file,"PUSH R%d\n",reg1);
			fprintf(target_file,"PUSH R%d\n",reg1);
			fprintf(target_file,"CALL 0\n");
			fprintf(target_file,"POP R%d\n",reg1);
			fprintf(target_file,"POP R%d\n",reg1);
			fprintf(target_file,"POP R%d\n",reg1);
			fprintf(target_file,"POP R%d\n",reg1);
			fprintf(target_file,"POP R%d\n",reg1);
			free_register();
			free_register();
			return -1;
        
        case _IF_THEN_ELSE:
            _else= next_label();
            _endif= next_label();
            l= codeGen(t->left);
            fprintf(target_file,"JZ R%d, L%d\n", l, _else);
            free_register();
            m= codeGen(t->mid);
            fprintf(target_file, "JMP L%d\n",_endif);
            fprintf(target_file,"L%d:\n",_else);
            r= codeGen(t->right);
            fprintf(target_file,"L%d:\n",_endif);
            return -1;
        
        case _IF_THEN:
            _endif= next_label();
            l= codeGen(t->left);
            fprintf(target_file,"JZ R%d, L%d\n",l, _endif);
            free_register();
            m= codeGen(t->mid);
            fprintf(target_file,"L%d:\n", _endif);
            return -1;
        
        case _WHILE:
            _while_start= next_label();
            _while_end= next_label();
            push_to_LL(_while_start, _while_end); //for break and continue statements
            fprintf(target_file, "L%d:\n", _while_start);
            l= codeGen(t->left);
            fprintf(target_file,"JZ R%d, L%d\n",l, _while_end);
            free_register();
            m= codeGen(t->mid);
            fprintf(target_file,"JMP L%d\n",_while_start);
            fprintf(target_file,"L%d:\n", _while_end);
            pop_from_LL();
            return -1;
        
        case _DO_WHILE:
            _while_start= next_label();
            _while_end= next_label();
            push_to_LL(_while_start, _while_end);
            fprintf(target_file, "L%d\n", _while_start);
            m= codeGen(t->mid);
            l= codeGen(t->left);
            fprintf(target_file, "JNZ R%d, L%d\n", l, _while_start);
            free_register();
            fprintf(target_file,"L%d:\n", _while_end);
            pop_from_LL();
            return -1;
        
        case _REAPEAT_UNTIL:
            _while_start= next_label();
            _while_end= next_label();
            push_to_LL(_while_start, _while_end);
            fprintf(target_file, "L%d:\n", _while_start);
            m= codeGen(t->mid);
            l= codeGen(t->left);
            fprintf(target_file, "JZ R%d, L%d\n",l, _while_start);
            free_register();
            fprintf(target_file,"L%d:\n", _while_end);
            pop_from_LL();
            return -1;
        
        case _BREAK:
            if(loop_head!=NULL)
                fprintf(target_file,"JMP L%d\n",loop_head->brk);
            return -1;
        case _CONTINUE:
            if(loop_head!=NULL)
                fprintf(target_file, "JMP L%d\n",loop_head->cnt);
            return -1;
    }
}
void end_program(){
		fprintf(target_file,"INT 10");
}
int type_guard(struct tnode* t){

    switch(t->nodetype){
        case _PLUS:
        case _MINUS:
        case _DIV:
        case _MUL:
        case _ASSIGN:
            if(t->left->type != _inttype || t->right->type!= _inttype){
                yyerror("type mismatch : both should be integer type\n");
                exit(1);
            }
            break;

        case _EQ:
        case _GE:
        case _LE:
        case _GT:
        case _LT:
            if(t->left->type != _inttype || t->right->type!= _inttype){
                yyerror("type mismatch : both should be boolean type\n");
                exit(1);
            }
            break;
        
        case _IF_THEN_ELSE:
        case _IF_THEN:
        case _WHILE:
        case _DO_WHILE:
        case _REAPEAT_UNTIL:
            if(t->left->type != _booltype){
                yyerror("type mismatch : conditions should be boolean\n");
                exit(1);
            }
            break;
        
        case _WRITE:
            if(t->left->type != _inttype){
                yyerror("type mismatch: write only possible with integers\n");
                exit(1);
            }

    }
    return 1;
}
