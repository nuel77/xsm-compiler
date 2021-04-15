%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <ctype.h>
	#include <string.h>
	int yyerror(char const *); 
	extern FILE* yyin;
	#include "header.h"
	#include "header.c"
	int yylex(void);
	enum VarType curr_type;
	int Ptype;
%}

%union{
    struct tnode* Node;
	struct Gnode* gnode;
};

%type <Node>  Body E Slist Stmt InputStmt OutputStmt AsgStmt Ifstmt Whilestmt Breakstmt Continuestmt 
%token NUM START  END  ASSIGN ID READ WRITE IF THEN ELSE ENDIF WHILE DO ENDWHILE BREAK CONTINUE REPEAT UNTIL  DECL ENDDECL INT STR STRING MAIN RETURN
%nonassoc LT GT LE GE NE EQ
%left PLUS MINUS
%left MUL DIV

%%

program: GdeclBlock FDefBlock MainBlock {exit(0);}
	|GdeclBlock MainBlock				{exit(0);}
	|MainBlock							{exit(0);}
;
GdeclBlock: DECL GDecllist ENDDECL  {
									
									initialxsmcode();
									Phead=NULL;
									Lhead=NULL;
									LOCAL_BIND=1;
									PARAM_BIND=1;
                            		}
	|DECL ENDDECL					{initialxsmcode();}
;

GDecllist: GDecllist GDec1
	| GDec1
;
GDec1: Type GidList ';'				
;
Type: INT							{curr_type= _inttype;}
	|STR							{curr_type= _strtype;}
;
GidList: GidList ',' Gid
	|Gid
;

Gid: ID								{GInstall($<Node>1->varname, curr_type, 1, 1, _ID, NULL);}
	|ID '[' NUM ']'					{GInstall($<Node>1->varname, curr_type, $<Node>3->val, 1, _ARRAY, NULL);}
	|ID '[' NUM ']' '[' NUM ']'		{GInstall($<Node>1->varname, curr_type, $<Node>3->val, $<Node>6->val, _MATRIX, NULL);}
	|MUL ID
	|ID '(' ParamList ')'			{GInstall($<Node>1->varname, curr_type, 0, 0, _FUNC, Phead);Phead=NULL;}
;

FDefBlock: FDefBlock Fdef			
	| Fdef
;
Fdef: Type ID '(' ParamList ')' '{' LdeclBlock Body '}'	{funcdef(curr_type,$<Node>2, Phead,$<Node>8);
														print_local_declarations(Lhead);
														Phead= NULL;
														Lhead=NULL;
														LOCAL_BIND=1;
														PARAM_BIND=1;
}
;
MainBlock: INT MAIN '(' ')' '{' LdeclBlock Body '}'		{mainfuncdef($<Node>7);
														Lhead=NULL;
														Phead=NULL;
														LOCAL_BIND=1;
														PARAM_BIND=1;
														}	
;
ParamList: ParamList ',' Param
	| Param 
;
Param: Ptype ID	{
		struct Paramstruct *temp;
		temp= PLookup($<Node>2->varname);
		if(temp!=NULL){
			printf("Multiple declarations for %s in paramlist",$<Node>2->varname);
			exit(0);
		}
		PInstall($<Node>2->varname, Ptype, _ID);
	}
	| MUL Ptype ID		{PInstall($<Node>3->varname, Ptype,_PTR);}
;

Ptype: INT 					{Ptype= _inttype;}
	| STR                   {Ptype= _strtype;}
;

LdeclBlock: DECL LDecList ENDDECL
	| DECL ENDDECL;
;

LDecList: LDecList LDecl
	| LDecl;
;

LDecl: Ptype IdList ';'
;

IdList: IdList ',' ID		{LInstall($<Node>3->varname, Ptype, _ID);}
	| IdList ',' MUL ID		{LInstall($<Node>4->varname, Ptype, _PTR);}
	| ID					{LInstall($<Node>1->varname, Ptype, _ID);}
	| MUL ID				{LInstall($<Node>2->varname, Ptype, _PTR);}
;

Body: START Slist END		{$<Node>$= $<Node>2;}
	|START END				{$<Node>$= NULL;}
;

Slist: Slist Stmt       {$<Node>$= createTree(VAL_NONE, _typeless, "\0", _CONNECTOR, $<Node>1,NULL,$<Node>2);}
    | Stmt              {$<Node>$= $<Node>1;}
;

Stmt : InputStmt ';'		{$<Node>$=$<Node>1;}
	| OutputStmt ';' 	    {$<Node>$=$<Node>1;}
	| AsgStmt ';'		    {$<Node>$=$<Node>1;}
    | Ifstmt  ';'           {$<Node>$=$<Node>1;}
    | Whilestmt ';'         {$<Node>$=$<Node>1;}
    | Breakstmt  ';'        {$<Node>$=$<Node>1;}
    | Continuestmt ';'      {$<Node>$=$<Node>1;}
	| Returnstmt ';'		{$<Node>$=$<Node>1;}
;

InputStmt: READ '(' ID ')'      		{$<Node>$= createTree(VAL_NONE, _typeless, "\0", _READ, $<Node>3,NULL,NULL);}
		| READ '(' ID '[' E ']' ')'		{$<Node>$ = createTree(VAL_NONE, _typeless, "\0", _READ_ARRAY, $<Node>3, $<Node>5, NULL);}
;

OutputStmt: WRITE '(' E ')'     {$<Node>$= createTree(VAL_NONE, _typeless, "\0", _WRITE, $<Node>3,NULL,NULL);}
;

AsgStmt: ID ASSIGN E            {$<Node>$= createTree(VAL_NONE, _inttype, "\0", _ASSIGN, $<Node>1,NULL,$<Node>3);}
	| ID '[' E ']' ASSIGN E		{$<Node>$ = createTree(0, _inttype, "\0", _ASGN_ARRAY,$<Node>1, $<Node>3, $<Node>6);}
;

Ifstmt: IF '(' E ')' THEN Slist ELSE Slist ENDIF    {$<Node>$= createTree(VAL_NONE, _typeless, "\0", _IF_THEN_ELSE, $<Node>3,$<Node>6,$<Node>8);}
    | IF '(' E ')' THEN Slist ENDIF                 {$<Node>$= createTree(VAL_NONE, _typeless, "\0", _IF_THEN, $<Node>3, $<Node>6, NULL);}

Whilestmt: WHILE '(' E ')' DO Slist ENDWHILE        {$<Node>$= createTree(VAL_NONE, _typeless, "\0", _WHILE, $<Node>3, $<Node>6 ,NULL);}
    | REPEAT Slist UNTIL '(' E ')'                  {$<Node>$= createTree(VAL_NONE, _typeless, "\0", _REAPEAT_UNTIL, $<Node>5, $<Node>2, NULL);}
    | DO Slist WHILE '(' E ')'                      {$<Node>$= createTree(VAL_NONE, _typeless, "\0", _DO_WHILE, $<Node>5, $<Node>2, NULL);} 
;

Continuestmt: CONTINUE                              {$<Node>$= createTree(VAL_NONE, _typeless, "\0", _CONTINUE, NULL, NULL, NULL);}
;

Breakstmt: BREAK                                    {$<Node>$= createTree(VAL_NONE, _typeless, "\0", _BREAK, NULL, NULL, NULL);}
;

Returnstmt: RETURN E 								{$<Node>$= createTree(VAL_NONE, _typeless, "\0", _RET, $<Node>2, NULL, NULL);}
;

ArgList: ArgList ',' E								{$<Node>$= createTree(VAL_NONE,_typeless, "\0", _ARG,  $<Node>1, NULL, $<Node>3);}
	| E												{$<Node>$= createTree(VAL_NONE, _typeless, "\0", _ARG, NULL, NULL, $<Node>1);}
;

E 	: E PLUS E 		{$<Node>$ = createTree(VAL_NONE, _inttype, "\0", _PLUS, $<Node>1, NULL, $<Node>3);}
	| E MINUS E 	{$<Node>$ = createTree(VAL_NONE, _inttype, "\0", _MINUS, $<Node>1, NULL, $<Node>3);}
	| E MUL E 		{$<Node>$ = createTree(VAL_NONE, _inttype, "\0", _MUL, $<Node>1, NULL, $<Node>3);}
	| E DIV E 		{$<Node>$ = createTree(VAL_NONE, _inttype, "\0", _DIV, $<Node>1, NULL, $<Node>3);}
	| '(' E ')' 	{$<Node>$ = $<Node>2;}
	| E EQ E 		{$<Node>$ = createTree(VAL_NONE, _booltype, "\0", _EQ, $<Node>1, NULL, $<Node>3);}
	| E NE E 		{$<Node>$ = createTree(VAL_NONE, _booltype, "\0", _NE, $<Node>1, NULL, $<Node>3);}
	| E LE E		{$<Node>$ = createTree(VAL_NONE, _booltype, "\0", _LE, $<Node>1, NULL, $<Node>3);}
	| E GE E 		{$<Node>$ = createTree(VAL_NONE, _booltype, "\0", _GE, $<Node>1, NULL, $<Node>3);}
	| E LT E 		{$<Node>$ = createTree(VAL_NONE, _booltype, "\0", _LT, $<Node>1, NULL, $<Node>3);}
	| E GT E  		{$<Node>$ = createTree(VAL_NONE, _booltype, "\0", _GT, $<Node>1, NULL, $<Node>3);}
	| NUM 			{$<Node>$ = $<Node>1;}
	| STRING		{$<Node>$ = $<Node>1;}		
	| ID			{$<Node>$ = $<Node>1;}
	| ID '[' E ']'	{$<Node>$ = createTree(VAL_NONE, $<Node>1->type, $<Node>1->varname, _ARRAY, $<Node>1, $<Node>3, NULL);}
	| ID '(' ArgList ')' {$<Node>$= createTree(VAL_NONE, $<Node>1->type, $<Node>1->varname, _FUNC, $<Node>1, NULL, $<Node>3);}
;

%%
int yyerror(char const *s){
	printf("yyerror %s",s);
}

int main(int argc, char *argv[]) 
{	
	FILE *fp = fopen(argv[1],"r");
	if(fp)
		yyin=fp;
	target_file=fopen("target.xsm","w");	
	yyparse();
	return 0;
}