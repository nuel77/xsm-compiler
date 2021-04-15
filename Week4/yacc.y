%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <ctype.h>
	#include <string.h>
	#include "header.h"
	int yylex(void);
	FILE* yyin;
    extern FILE* target_file;
	extern int yyerror(char const *);
	int out;  
	enum VarType curr_type;
	
%}

%union{
    struct tnode* Node;
	struct Gnode* gnode;
};

%type <Node>  program Body E Slist Stmt InputStmt OutputStmt AsgStmt Ifstmt Whilestmt Breakstmt Continuestmt 
%token NUM START END  ASSIGN ID READ WRITE IF THEN ELSE ENDIF WHILE DO ENDWHILE BREAK CONTINUE REPEAT UNTIL  DECL ENDDECL INT STR STRING
%nonassoc LT GT LE GE NE EQ
%left PLUS MINUS
%left MUL DIV

%%

program: Declarations Body  {
                            $<Node>$ = $<Node>2;
							print_declarations();
							printf("stack start: %d\n",CURR_BINDING);
							setBinding();
							out= codeGen($<Node>2);
							end_program();
                            printf("Evaluating..\n");
                            exit(0);
                            }
;


Declarations: DECL Decllist ENDDECL 
			|DECL ENDDECL			
;

Decllist: Decllist Dec1
	  | Dec1
;
Dec1: Type Varlist ';'				
;
Type: INT							{curr_type= _inttype;}
	|STR							{curr_type= _strtype;}
;
Varlist: Varlist ',' ID				{Install($<Node>3->varname, curr_type, 1, 1, _ID);}
	|Varlist ',' ID '[' NUM ']'		{Install($<Node>3->varname, curr_type, $<Node>5->val, 1, _ARRAY);}
	|ID '[' NUM ']'					{Install($<Node>1->varname, curr_type, $<Node>3->val, 1, _ARRAY);}
	|ID								{Install($<Node>1->varname, curr_type, 1, 1, _ID);}
;



Body: START Slist END		{ $<Node>$= $<Node>2;}
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
	fprintf(target_file,"0\n2056\n0\n0\n0\n0\n0\n0\n");
	yyparse();
	return 0;
}