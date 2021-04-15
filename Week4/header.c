#include"header.h"
#include<stdio.h>
#include<stdlib.h>
#include <ctype.h>
#include<string.h>

extern int yyerror(char const *);
struct loop_label_node *loop_head=NULL;

void setBinding(){
    fprintf(target_file,"MOV SP, %d\n", CURR_BINDING);
}
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

struct Gsymbol* Lookup(char *name){
    struct Gsymbol *curr= Ghead;
    while(curr != NULL){
        if(strcmp(curr->name, name)==0)
            return curr;
        curr= curr->next;
    }
    return NULL;
}

void Install(char *name, int type, int size1, int size2,int nodetype){
    struct Gsymbol *tmp;
    tmp= Lookup(name);
    if(tmp!=NULL){
        printf("Same variable name already declare! %s\n",name);
        exit(0);
    }
    if(CURR_BINDING > 5120){
        printf("Stack overflow\n");
        exit(0);
    }
    tmp = (struct Gsymbol*) malloc(sizeof(struct Gsymbol));
    tmp->name= name;
    tmp->type= type;
    tmp->size1= size1;
    tmp->size2= size2;
    tmp->nodetype= nodetype;
    tmp->binding= CURR_BINDING;
    tmp->next= NULL;
    
    CURR_BINDING += size1*size2;
    printf("binding updated:%d\n",CURR_BINDING);
    if(Ghead==NULL){
        Ghead= tmp;
    }
    else{
        tmp->next= Ghead;
        Ghead= tmp;
    }
}

struct tnode * createTree(int val,  enum VarType type, char *varname, enum NodeType nodetype, struct tnode* left, struct tnode* mid, struct tnode* right){

    struct tnode *temp;
    temp= (struct tnode*)malloc(sizeof(struct tnode));
    temp->val= val;
    temp->type= type;
    temp->nodetype= nodetype;
    temp->varname=malloc(sizeof(varname));
    strcpy(temp->varname, varname);

    struct Gsymbol *g ;
    g= malloc(sizeof(struct Gsymbol));

    switch(nodetype){
        case _ID:
        case _ARRAY:
            g= Lookup(temp->varname);
            if(g!=NULL){
                temp->type= g->type;
            }
            temp->Gentry= g;
            break;
    }
    
    temp->left=left;
    temp->mid= mid;
    temp->right=right;

    if(type_guard(temp)){
        return temp;
    }
    else {
        printf("Now exiting\n");
        exit(1);
    }
    
}

void print_declarations(){
    struct Gsymbol* curr= Ghead;
    while(curr!=NULL){
        printf("name : %s, ",curr->name);
        printf("size : %d, ",curr->size1);
        printf("binding: %d, ",curr->binding);
        printf("type: %d, ",curr->type);
        printf("\n");
        curr=curr->next;
    }
}

int codeGen(struct tnode* t){
    int l ,r, m, _else, _endif, reg1, reg2, location, _while_start,_while_end;
    struct Gsymbol* temp;

    if(t== NULL) return -1;

    switch(t->nodetype){
        case _NUM:
            reg1= get_register();
            fprintf(target_file,"MOV R%d, %d\n",reg1, t->val);
            return reg1;
        case _STR:
            reg1= get_register();
            fprintf(target_file,"MOV R%d, \"%s\"\n", reg1, t->varname);
            return reg1;
        case _ID:
            reg1= get_register();
            temp= Lookup(t->varname);
            if(temp==NULL) {
                printf("unknown variable :%s\n", t->varname);
                exit(1);
            }
            location= temp->binding;
            fprintf(target_file, "MOV R%d,[%d]\n", reg1, location);
            return reg1;

        case _ARRAY:    
            temp= Lookup(t->varname);
            if(temp==NULL){
                printf("Unknown variable: %s\n", t->varname);
                exit(0);
            }
            m= codeGen(t->mid);
            location= temp->binding;
            fprintf(target_file,"ADD R%d, %d\n",m, location);
            fprintf(target_file,"MOV R%d, [R%d]\n",m,m);
            return m;

        case _MATRIX:   break;
        case _PTR:      break;
        case _ADDR:     break;

        case _ASSIGN:
			r = codeGen(t->right);
			temp=Lookup(t->left->varname);
			if(temp==NULL)
			{
				printf("Unknown variable: %s\n", t->varname);
                exit(0);
            }
			location= temp->binding;
			fprintf(target_file,"MOV [%d], R%d\n", location, r);
			free_register();
			return -1;
        
        case _ASGN_ARRAY:
            r= codeGen(t->right);
            m= codeGen(t->mid);
            temp=Lookup(t->left->varname);
            if(temp==NULL){
                printf("Unknown variable: %s\n", t->varname);
                exit(0);
            }
            location= temp->binding;
            fprintf(target_file, "ADD R%d, %d\n",m, location);
            fprintf(target_file,"MOV [R%d], R%d\n",m, r);
            free_register();
            free_register();
            return -1;
        case _ASGN_MATRIX:  break;
        case _ASGN_PTR:     break;
        case _ASGN_PTR_ADDR:break;
            
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
            temp= Lookup(t->left->varname);
            if(temp==NULL){
                printf("no such variale: %s\n",t->left->varname);
                exit(1);
            }
            location= temp->binding;
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
        
        case _READ_ARRAY:  
            temp= Lookup(t->left->varname);
            if(temp==NULL){
                printf("undefined variable %s", t->left->varname);
                exit(1);
            }
            reg1= get_register();
            m= codeGen(t->mid);
            location= temp->binding;
            fprintf(target_file,"ADD R%d, %d\n", m, location );
            fprintf(target_file,"MOV R%d, \"Read\"\n", reg1);
            fprintf(target_file,"PUSH R%d\n",reg1);
			fprintf(target_file,"MOV R%d, -1\n",reg1);
			fprintf(target_file,"PUSH R%d\n",reg1);
			fprintf(target_file,"MOV R%d, R%d\n",reg1,m);
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
            free_register();
            return -1;
        case _READ_MATRIX:  break;
        case _READ_PTR :    break;

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
            if(t->left->type == _typeless|| t->left->type== _booltype){
                yyerror("type mismatch: write only possible with integers and strings\n");
                exit(1);
            }
            break;
        case _ASSIGN:
            
            if(t->left->type!=t->right->type){
                yyerror("type mismatch: assign types not same!\n");
                exit(1);
            }
            break;
        case _ASGN_ARRAY:
            if(t->mid->type!= _inttype){
                yyerror("array index must be type integer!");
                exit(1);
            }
            if(t->left->type != t->right->type){
                yyerror("type mismatch:assign types not same!\n");
                exit(1);
            }
            break;
        case _READ_ARRAY:
            if(t->mid->type!= _inttype){
                yyerror("array index must be type integer!");
                exit(1);
            }
            break;
    }
    return 1;
}

int vartype_guard(struct tnode* t){

    return 1;
}
 
