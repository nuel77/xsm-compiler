#ifndef EXP2_HEADER

#include<stdio.h>
#define EXP2_HEADER
#define STACK_START 4096

enum nodeType{
	_VARIABLE=0, _NUM, _ASSIGN, _PLUS, _MINUS, _MUL, _DIV, _CONNECTOR, _WRITE , _READ

};  

struct tnode { 
	int val;		//value only for NUM nodes
	int var_type;	//variable type
	char var_name;	//variable name
	enum nodeType type_of_node;	//type of node 
	struct tnode *left,*right;
};

static int reg_count=0;
FILE *target_file;
int variables[26];

struct tnode* createTree(int val,int var_type, char var_name ,enum nodeType type_of_node, struct tnode * l, struct tnode * r);
int evaluate(struct tnode*);
int generateCode(struct tnode *);
int getRegister(void);
void freeRegister(void);

#endif