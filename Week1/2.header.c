#include"2.header.h"
#include<stdlib.h>
#include<stdio.h>
extern int REG;
extern FILE* target_file;


struct tnode* makeLeafNode(int n)
{
	struct tnode *temp;
	temp = (struct tnode*)malloc(sizeof(struct tnode));
	temp->op = NULL;
	temp->val = n;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

struct tnode* makeOperatorNode(char c,struct tnode *l,struct tnode *r)
{
	struct tnode *temp;
	temp = (struct tnode*)malloc(sizeof(struct tnode));
	temp->op = malloc(sizeof(char));
	*(temp->op) = c;
	temp->left = l;
	temp->right = r;
	return temp;
}

int codeGen(struct tnode *t)
{
	int x,y;	
	if(t->op == NULL)
	{
		x = getReg();
		fprintf(target_file,"MOV R%d, %d\n",x,t->val);
	}
	else
	{
		x = codeGen(t->left);
		y = codeGen(t->right);
		switch(*(t->op))
		{
			case '+' : {
					fprintf(target_file,"ADD R%d, R%d\n",x,y);
				}
			break;
			case '-' : {
					fprintf(target_file,"SUB R%d, R%d\n",x,y);
				}
			break;
			case '*' : {
					fprintf(target_file,"MUL R%d, R%d\n",x,y);
				}
			break;
			case '/' : {
					fprintf(target_file,"DIV R%d, R%d\n",x,y);
				}
			break;
		}
		freeReg();
	}
	return x;
}

int getReg()
{
	if(REG>=20){
		printf("Out of registers\n");
		exit(1);
	}
	return REG++;
}

void freeReg()
{
	if(REG>0)
		REG--;
}
