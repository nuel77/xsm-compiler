#include"1.header.h"
#include<stdio.h>
#include<stdlib.h>

int getRegister(){
	if(reg_count>=20){
		printf("out of registers!\n");
		exit(1);
	}
	else return reg_count++;

}

void freeRegister(){
	reg_count--;
}

struct tnode* createTree(int val,int var_type, char var_name ,enum nodeType type_of_node, struct tnode * l, struct tnode * r){
	struct tnode *temp;
	temp = (struct tnode*)malloc(sizeof(struct tnode));
	temp->val=val;
	temp->var_type=var_type;
	temp->var_name=var_name;
	temp->type_of_node = type_of_node;
	temp->left= l; //only left node present for READ, WRITE etc
	temp->right= r;
	return temp;
}

int evaluate(struct tnode *t)
{
	if(t == NULL)
		return -1;

	switch(t->type_of_node)
	{			
		case _ASSIGN :	
			variables[(t->left->var_name)-'a'] = evaluate(t->right);
			return variables[(t->left->var_name)-'a'];
		
		case _VARIABLE :
			return variables[t->var_name -'a'];

		case _NUM :
			return t->val;

		case _PLUS :
			return evaluate(t->left) + evaluate(t->right);

		case _MINUS:
			return evaluate(t->left) - evaluate(t->right);

		case _MUL :
			return evaluate(t->left) * evaluate(t->right);
		
		case _DIV :
			return evaluate(t->left) / evaluate(t->right);
			
		case _CONNECTOR :
			evaluate(t->left);
			evaluate(t->right);
			return -1;

		case _READ :
			return scanf("%d",&variables[(t->left->var_name)-'a']);

		case _WRITE :
			return printf("%d\n",evaluate(t->left));

	}
}
int generateCode(struct tnode *t){
	
	int reg, reg1,reg2, location;
	if(t==NULL) return -1;

	switch(t->type_of_node){

		case _NUM : 
			reg= getRegister();
			fprintf(target_file,"MOV R%d,%d\n", reg, t->val);
			return reg;

		case _VARIABLE :
			reg= getRegister();
			location= STACK_START + t->var_name-'a';
			fprintf(target_file,"MOV R%d,[%d]\n", reg, location) ;
			return reg; 

		case _ASSIGN :
			reg= generateCode(t->right);
			location= STACK_START + t->left->var_name-'a';
			fprintf(target_file,"MOV [%d],R%d\n",location,reg);
			freeRegister();
			return reg;

		case _PLUS :
			reg1= generateCode(t->left);
			reg2= generateCode(t->right);
			fprintf(target_file,"ADD R%d,R%d\n",reg1,reg2);
			freeRegister();
			return reg1;
		case _MINUS :
			reg1= generateCode(t->left);
			reg2= generateCode(t->right);
			fprintf(target_file,"SUB R%d,R%d\n",reg1,reg2);
			freeRegister();
			return reg1;
		case _MUL :
			reg1= generateCode(t->left);
			reg2= generateCode(t->right);
			fprintf(target_file,"MUL R%d,R%d\n",reg1,reg2);
			freeRegister();
			return reg1;
		case _DIV :
			reg1= generateCode(t->left);
			reg2= generateCode(t->right);
			fprintf(target_file,"DIV R%d,R%d\n",reg1,reg2);
			freeRegister();
			return reg1;

		case _CONNECTOR:
			generateCode(t->left);
			generateCode(t->right);
			return -1;

		case _READ :
			reg= getRegister();	//read input will be stored in this register
			location= STACK_START + t->left->var_name-'a';
			printf("-deb location= %c\n",location);

			fprintf(target_file,"MOV R%d, \"Read\"\n",reg);	//callname
			fprintf(target_file,"PUSH R%d\n",reg);
			fprintf(target_file,"MOV R%d,-1\n",reg);	//arg 1
			fprintf(target_file,"PUSH R%d\n",reg);
			fprintf(target_file,"MOV R%d, %d\n",reg,location);	//arg 2
			fprintf(target_file,"PUSH R%d\n",reg);
			fprintf(target_file,"PUSH R%d\n",reg);		//no arg 3
			fprintf(target_file,"PUSH R%d\n",reg);		//return register
			fprintf(target_file,"CALL 0\n");

			fprintf(target_file,"POP R%d\n",reg);
			fprintf(target_file,"POP R%d\n",reg);
			fprintf(target_file,"POP R%d\n",reg);
			fprintf(target_file,"POP R%d\n",reg);
			fprintf(target_file,"POP R%d\n",reg);

			freeRegister();
			return reg;
		
		case _WRITE :
			reg1 = generateCode(t->left); //contains value to be written
			reg = getRegister();

			fprintf(target_file,"MOV R%d, \"Write\"\n",reg); //callname
			fprintf(target_file,"PUSH R%d\n",reg);
			fprintf(target_file,"MOV R%d, -2\n",reg);	//arg1
			fprintf(target_file,"PUSH R%d\n",reg);
			fprintf(target_file,"PUSH R%d\n",reg1);		//arg2
			fprintf(target_file,"PUSH R%d\n",reg);
			fprintf(target_file,"PUSH R%d\n",reg);
			fprintf(target_file,"CALL 0\n");

			fprintf(target_file,"POP R%d\n",reg);
			fprintf(target_file,"POP R%d\n",reg);
			fprintf(target_file,"POP R%d\n",reg);
			fprintf(target_file,"POP R%d\n",reg);
			fprintf(target_file,"POP R%d\n",reg);

			freeRegister();
			return reg1;
	}
}
