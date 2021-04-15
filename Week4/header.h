#ifndef STAGE4_HEADER_H
#define STAGE4_HEADER_H
#include<stdio.h>
#include<stdlib.h>
#define VAL_NONE 0
#define STACK_START 4096
#define VARNAME_NONE "\0"
static int REG_COUNT=0, LABEL_COUNT=0, CURR_BINDING= 4096;

enum NodeType{
    _ID=0, _NUM, _ASSIGN, _PLUS,_MINUS, _DIV, _MUL,_MOD, _CONNECTOR, _WRITE, _READ, _EQ,_NE, _GE, _LE, _GT,_LT, _IF_THEN_ELSE, _IF_THEN, _WHILE,
    _BREAK, _CONTINUE, _REAPEAT_UNTIL, _DO_WHILE, _STR, _ARRAY,_READ_ARRAY, _ASGN_ARRAY, _MATRIX, _ASGN_MATRIX, _READ_MATRIX, _ADDR, _PTR, _ASGN_PTR,
    _READ_PTR, _ASGN_PTR_ADDR
};
enum VarType{
    _typeless=-1, _booltype, _inttype,_strtype
};

struct Gsymbol{
	char *name;     //name of the variable
	enum VarType type;  //type of variable
	int size1;      //sizeof the type of the variable
	int size2;      //for 2D arrays
	enum NodeType nodetype;  //stores the node type for AST
	int binding;    //stores the static memory address allocated
	struct Gsymbol *next;
};

struct tnode{
    int val;            //value of NUM 
    enum VarType type;  //variable type of node, typless, integer and boolean
    char *varname;       //name of the variable 
    enum NodeType nodetype; //type of node eg: READ,WRITE, CONNECTOR, IF_ELSE etc
    struct Gsymbol *Gentry; //pointer to Global Symbol Table entry for global variables and functions
    struct tnode *left,*mid,*right; //mid node is present in IF type, for true part 
};

struct loop_label_node{
    int brk, cnt;
    struct loop_label_node *next;
};

struct Gsymbol *Ghead;
FILE* target_file;
int variable_array[26];

struct tnode * createTree(int val,  enum VarType type, char* varname, enum NodeType nodetype, struct tnode* left, struct tnode* mid, struct tnode* right);
int evaluate(struct tnode*);
int codeGen(struct tnode*t);
void end_program(void);

int get_register(void);
void free_register(void);
int next_label(void);
int type_guard(struct tnode*);

void push_to_LL(int,int);
void pop_from_LL(void);

struct Gsymbol *Lookup(char * name);
void Install(char *name, int type, int size1, int size2,int nodetype);
int vartype_guard(struct tnode *t);
void print_declarations();
void setBinding();

void printNode(struct tnode* t);
#endif