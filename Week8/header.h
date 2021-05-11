#ifndef STAGE6_HEADER_H
#define STAGE6_HEADER_H
#include<stdio.h>
#include<stdlib.h>
#define VAL_NONE 0
#define STACK_START 4096
#define VARNAME_NONE "\0"
static int REG_COUNT=-1, LABEL_COUNT=0, CURR_BINDING= 4096, LOCAL_BIND=1, PARAM_BIND=1,flabel=0,F_INDEX=0,C_INDEX=0, START_FUNC;

enum NodeType{
    _ID=0, _NUM, _ASSIGN, _PLUS,_MINUS, _DIV, _MUL,_MOD, _CONNECTOR, _WRITE, _READ, _EQ,_NE, _GE, _LE, _GT,_LT, _IF_THEN_ELSE, _IF_THEN, _WHILE,
    _BREAK, _CONTINUE, _BRKP, _REAPEAT_UNTIL, _DO_WHILE, _STR, _ARRAY,_READ_ARRAY, _ASGN_ARRAY, _MATRIX, _ASGN_MATRIX, _READ_MATRIX, _ADDR, _PTR, _ASGN_PTR,
    _READ_PTR, _ASGN_PTR_ADDR, _FUNC, _RET, _ARG,_INIT, _ALLOC,_FREE, _FIELD, _ASSIGN_FIELD, _READ_FIELD, _NULL, _DELETE, _NEW, _METHOD1,_METHOD2,_METHOD3
};
struct Classtable{
    char *name;
    struct Fieldlist *Memberfield;
    struct Memberfunclist *Vfuncptr;
    struct Classtable *Parentptr;
    int class_idx;
    int Fieldcount;
    int Methodcount;
    struct Classtable *next;
};
struct Fieldlist{
    char *name;
    int fieldIndex;
    struct Classtable *Ctype;
    struct Typetable *type;
    struct Fieldlist *next;
};

struct Memberfunclist{
    char *name;
    struct Typetable *type;
    struct Paramstruct *paramlist;
    int Funcposition ;
    int flabel;
    struct Memberfunclist *next;
};

struct Typetable{
    char *name;
	int size;
	struct Fieldlist *fields;
    struct Typetable *next;
};

struct Paramstruct {
    char *name;
    struct Typetable *type;
    int binding;
    int nodetype;
    struct Paramstruct  *next;
};

struct Lsymbol{
    char *name;
    struct Typetable *type;
    int binding;
    int nodetype;
    struct Lsymbol *next;
};

struct Gsymbol{
	char *name;     //name of the variable
	struct Typetable *type;  //typetable pointer of variable
    struct Classtable *Ctype;
	int size1;      //sizeof the type of the variable
	int size2;      //for 2D arrays
	enum NodeType nodetype;  //stores the node type for AST
	int binding;    //stores the static memory address allocated
    struct Paramstruct  *paramlist;//pointer to the head of the formal parameter list in the case of functions
    int flabel; //a label for identifying the starting address of a function's code
	struct Gsymbol *next;
};

struct tnode{
    int val;            //value of NUM 
    struct Typetable *type;  //variable type of node, typless, integer and boolean
    char *varname;       //name of the variable 
    enum NodeType nodetype; //type of node eg: READ,WRITE, CONNECTOR, IF_ELSE etc
    struct Gsymbol *Gentry; //pointer to Global Symbol Table entry for global variables and functions
    struct Lsymbol *Lentry; //pointer to the function's LST for local variables and arguements
    struct tnode *left,*mid,*right; //mid node is present in IF type, for true part 
};

union Constant{
    int intval;
    char* strval;
};

struct loop_label_node{
    int brk, cnt;
    struct loop_label_node *next;
};

struct Paramstruct *Phead;
struct Gsymbol *Ghead;
struct Lsymbol *Lhead;
struct loop_label_node *loop_head;
struct Typetable *Thead;
struct Fieldlist *Fhead;
struct Classtable *Chead,*Ctail ,*Class;
struct Memberfunclist *Mhead,*Mtail;
struct Fieldlist *Fhead,*Ftail;

FILE* target_file;
int variable_array[26];

struct tnode * createTree(int val,  struct Typetable *type, char* varname, enum NodeType nodetype, struct tnode* left, struct tnode* mid, struct tnode* right);
int evaluate(struct tnode*);
int codeGen(struct tnode*t);
void end_program(void);

int get_label();
int get_register(void);
void free_register(void);
int next_label(void);
int type_guard(struct tnode*);

void push_to_LL(int,int);
void pop_from_LL(void);

//type table functions
void TypeTableCreate();
int GetSize (struct Typetable *type);
int Typesizeallocator (struct Typetable *type);
void printTypetable();

//filed functions
void printField(struct Fieldlist *temp);
void printFieldType(struct Typetable *type);


struct Gsymbol *GLookup(char * name);
struct Paramstruct *PLookup(char * name);
struct Lsymbol *LLookup(char *name);
struct Typetable* TLookup(char *name);
struct Fieldlist* FLookup(struct Typetable *type, char *name);
struct Classtable* Clookup(char *name);
struct Memberfunclist * Class_Mlookup(struct Classtable *ctype, char * name);
struct Fieldlist * Class_Flookup(struct Classtable *ctype, char *name);

void GInstall(char *name, struct Typetable *type, struct Classtable *Ctype, int size1, int size2, enum NodeType nodetype, struct Paramstruct *paramlist);
void LInstall(char *name, struct Typetable *type, enum NodeType nodetype);
void PInstall(char *name, struct Typetable *type,  enum NodeType nodetype);
void TInstall(char *name,int size, struct Fieldlist *fields);
void FInstall(struct Typetable *type,char *name);
void CInstall(char *name, char *parent_class_name);
void Class_FInstall(struct Classtable *class_ptr, char *typename, char *name);
void Class_MInstall(struct Classtable * class_ptr, char *name, struct Typetable *type, struct Paramstruct *paramlist);

void mainfuncdef(struct tnode *body);
void funcdef(struct Typetable *type, struct Classtable *Ctype, struct tnode *func, struct Paramstruct *Phead, struct tnode *body);
int getFlabel();

int vartype_guard(struct tnode *t);
void print_declarations(struct Gsymbol *node);
char *printvartype(int nodetype);

int check_equivalence(struct Paramstruct * ,struct Paramstruct *);
void printNode(struct tnode* t);
char *printType(struct Typetable *type);

void printClasstable();
void printField1(struct Typetable *type);
void printFieldType(struct Typetable *type);
void printClassType(struct Classtable *Ctype);
void printField2(struct Classtable *Ctype);
void printMethod(struct Classtable *Ctype);
void printMethodtype(struct Typetable *type);

void reverseparamlist(struct Paramstruct *Phead);
char *getFunctionname(int label);
#endif