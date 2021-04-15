#include<stdio.h>

#ifndef TREE_HEADER
#define TREE_HEADER
struct tnode
{
	int val;
	char *op;
	struct tnode *left,*right;
};
struct tnode* makeLeafNode(int n);
struct tnode* makeOperatorNode(char c,struct tnode *l,struct tnode *r);
int codeGen(struct tnode *t);
int getReg(void);
void freeReg(void);
static int REG=0;
FILE *target_file;
#endif
