%{
    #include<stdlib.h>
    #include<stdio.h>
    #include"2.header.h"
    extern int yylex();
    extern int REG;
    extern FILE* target_file;
    void yyerror(char const *);   
%}

%union{
	struct tnode *Node;
    char charVal;
}

%type <Node> expr  
%token NEWLINE NUM
%left OP1
%left OP2

%%

program	: expr NEWLINE 		{
					int x=codeGen($<Node>1);a
					exit(1);
				}
;

expr: expr OP1 expr 	{$<Node>$ = makeOperatorNode($<charVal>2,$<Node>1,$<Node>3);}
	| expr OP2 expr 	{$<Node>$ = makeOperatorNode($<charVal>2,$<Node>1,$<Node>3);}
	| '(' expr ')' 		{$<Node>$ = $<Node>2;}
	| NUM 			    {$<Node>$ = $<Node>1;}
	;

%%

void yyerror(char const *s)
{
	printf("yyerror %s",s);
}

	
int main(void) 
{
	target_file=fopen("target_file1.xsm","w");
	fprintf(target_file,"0\n2056\n0\n0\n0\n0\n0\n0\n");
	yyparse();
	return 0;
}
