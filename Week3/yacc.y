%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <ctype.h>
	#include "header.h"
	extern int yylex(void);
	FILE* yyin;
    extern FILE* target_file;
	int yyerror(char const *);
	int out;  
%}

%union{
    struct tnode* Node;
};

%type <Node>  program E Slist Stmt InputStmt OutputStmt AsgStmt Ifstmt Whilestmt Breakstmt Continuestmt
%token NUM  START END  ASSIGN ID READ WRITE IF THEN ELSE ENDIF WHILE DO ENDWHILE BREAK CONTINUE REPEAT UNTIL 
%nonassoc LT GT LE GE NE EQ
%left PLUS MINUS
%left MUL DIV

%%

program: START Slist END   {
                            $<Node>$ = $<Node>2;
							out= codeGen($<Node>2);
							end_program();
                            printf("Evaluating..\n");
                            out= evaluate($<Node>2);
                            exit(0);
                            }
        |START END          {exit(0);}
;

Slist: Slist Stmt       {$<Node>$= createTree(VAL_NONE, _typeless, VARNAME_NONE, _CONNECTOR, $<Node>1,NULL,$<Node>2);}
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

InputStmt: READ '(' ID ')'      {$<Node>$= createTree(VAL_NONE, _typeless, VARNAME_NONE, _READ, $<Node>3,NULL,NULL);}
;

OutputStmt: WRITE '(' E ')'     {$<Node>$= createTree(VAL_NONE, _typeless, VARNAME_NONE, _WRITE, $<Node>3,NULL,NULL);}
;

AsgStmt: ID ASSIGN E            {$<Node>$= createTree(VAL_NONE, _inttype, VARNAME_NONE, _ASSIGN, $<Node>1,NULL,$<Node>3);}
;

Ifstmt: IF '(' E ')' THEN Slist ELSE Slist ENDIF    {$<Node>$= createTree(VAL_NONE, _typeless, VARNAME_NONE, _IF_THEN_ELSE, $<Node>3,$<Node>6,$<Node>8);}
    | IF '(' E ')' THEN Slist ENDIF                 {$<Node>$= createTree(VAL_NONE, _typeless, VARNAME_NONE, _IF_THEN, $<Node>3, $<Node>6, NULL);}

Whilestmt: WHILE '(' E ')' DO Slist ENDWHILE        {$<Node>$= createTree(VAL_NONE, _typeless, VARNAME_NONE, _WHILE, $<Node>3, $<Node>6 ,NULL);}
    | REPEAT Slist UNTIL '(' E ')'                  {$<Node>$= createTree(VAL_NONE, _typeless, VARNAME_NONE, _REAPEAT_UNTIL, $<Node>5, $<Node>2, NULL);}
    | DO Slist WHILE '(' E ')'                      {$<Node>$= createTree(VAL_NONE, _typeless, VARNAME_NONE, _DO_WHILE, $<Node>5, $<Node>2, NULL);} 
;

Continuestmt: CONTINUE                              {$<Node>$= createTree(VAL_NONE, _typeless, VARNAME_NONE, _CONTINUE, NULL, NULL, NULL);}
;

Breakstmt: BREAK                                    {$<Node>$= createTree(VAL_NONE, _typeless, VARNAME_NONE, _BREAK, NULL, NULL, NULL);}
;

E 	: E PLUS E 		{$<Node>$ = createTree(VAL_NONE, _inttype, VARNAME_NONE, _PLUS, $<Node>1, NULL, $<Node>3);}
	| E MINUS E 	{$<Node>$ = createTree(VAL_NONE, _inttype, VARNAME_NONE, _MINUS, $<Node>1, NULL, $<Node>3);}
	| E MUL E 		{$<Node>$ = createTree(VAL_NONE, _inttype, VARNAME_NONE, _MUL, $<Node>1, NULL, $<Node>3);}
	| E DIV E 		{$<Node>$ = createTree(VAL_NONE, _inttype, VARNAME_NONE, _DIV, $<Node>1, NULL, $<Node>3);}
	| '(' E ')' 	{$<Node>$ = $<Node>2;}
	| E EQ E 		{$<Node>$ = createTree(VAL_NONE, _booltype, VARNAME_NONE, _EQ, $<Node>1, NULL, $<Node>3);}
	| E NE E 		{$<Node>$ = createTree(VAL_NONE, _booltype, VARNAME_NONE, _NE, $<Node>1, NULL, $<Node>3);}
	| E LE E		{$<Node>$ = createTree(VAL_NONE, _booltype, VARNAME_NONE, _LE, $<Node>1, NULL, $<Node>3);}
	| E GE E 		{$<Node>$ = createTree(VAL_NONE, _booltype, VARNAME_NONE, _GE, $<Node>1, NULL, $<Node>3);}
	| E LT E 		{$<Node>$ = createTree(VAL_NONE, _booltype, VARNAME_NONE, _LT, $<Node>1, NULL, $<Node>3);}
	| E GT E  		{$<Node>$ = createTree(VAL_NONE, _booltype, VARNAME_NONE, _GT, $<Node>1, NULL, $<Node>3);}
	| NUM 			{$<Node>$ = $<Node>1;}
	| ID			{$<Node>$ = $<Node>1;}
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
	fprintf(target_file,"MOV SP, 4121\n");
	yyparse();
	return 0;
}