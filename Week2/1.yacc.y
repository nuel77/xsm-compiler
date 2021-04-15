%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "1.header.h"
	extern int yylex(void);
    int yyerror(char const *);
	int x;
%}

%union
{
	struct tnode *Node;
}

%type <Node> program E Slist Stmt InputStmt OutputStmt AsgStmt
%token NUM  ASSIGN START END READ WRITE ID
%left PLUS MINUS
%left MUL DIV

%%

program : START Slist END	{
					            $<Node>$ = $<Node>2;
					            x=generateCode($<Node>2);
					            fclose(target_file);
					            printf("Evaluating : \n");
					            x=evaluate($<Node>2);
					            exit(0);
				            }

	    | START END		    {exit(0);}
;


Slist : Slist Stmt 		    {$<Node>$ = createTree(0, 0,'0',_CONNECTOR,$<Node>1,$<Node>2);}
	| Stmt				    {$<Node>$=$<Node>1;}
;

Stmt : InputStmt ';'		{$<Node>$=$<Node>1;}
	| OutputStmt ';' 	    {$<Node>$=$<Node>1;}
	| AsgStmt ';'		    {$<Node>$=$<Node>1;}
;

InputStmt : READ '(' ID ')'		{$<Node>$ = createTree(0, 0,'0',_READ,$<Node>3,NULL);}
;

OutputStmt : WRITE '(' E ')'	{$<Node>$ = createTree(0, 0,'0',_WRITE,$<Node>3,NULL);}
;

AsgStmt : ID ASSIGN E 		    {$<Node>$ = createTree(0, 0,'0',_ASSIGN,$<Node>1,$<Node>3);}
;

E 	: E PLUS E 	    {$<Node>$ = createTree(0, 0,'0',_PLUS,$<Node>1,$<Node>3);}
	| E MINUS E 	{$<Node>$ = createTree(0, 0,'0',_MINUS,$<Node>1,$<Node>3);}
	| E MUL E 	    {$<Node>$ = createTree(0, 0,'0',_MUL,$<Node>1,$<Node>3);}
	| E DIV E 	    {$<Node>$ = createTree(0, 0,'0',_DIV,$<Node>1,$<Node>3);}
	| '(' E ')' 	{$<Node>$ = $<Node>2;}
	| NUM 			{$<Node>$ = $<Node>1;}
	| ID			{$<Node>$ = $<Node>1;}
;


%%

int yyerror(char const *s)
{
	printf("yyerror %s",s);
    return 1;
}

	
int main(void) 
{
	target_file=fopen("target.xsm","w");	
	fprintf(target_file,"0\n2056\n0\n0\n0\n0\n0\n0\n");
    /* 4095+26=4121 (26 locations used for static storage of variabes) */
	fprintf(target_file,"MOV SP, 4121\n"); 
	yyparse();
	return 0;
}
