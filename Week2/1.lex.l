%{
	#include <stdio.h>
    #include <stdlib.h>
    #include "1.header.h"
	#include "y.tab.h"
    extern int yyerror(char const *);
%}

%%

"begin"		{return START;}

"end"		{return END;}

"read"		{return READ;}

"write"		{return WRITE;}

[a-z]		{
			char var_name = *yytext;
			yylval.Node = createTree(0,0,var_name,_VARIABLE,NULL,NULL);
			return ID;
		}


[0-9]+ 		{
			int number = atoi(yytext); 
			yylval.Node = createTree(number,0,'0',_NUM,NULL,NULL);
			return NUM;
		}

"="		    {return ASSIGN;}
"+" 		{return PLUS;}
"-" 		{return MINUS;}
"*" 		{return MUL;}
"/" 		{return DIV;}
[\n \t] 	{}
[()] 		{return *yytext;}
[;]		    {return *yytext;}
.		    {yyerror("character error\n");    exit(1);}

%%

int yywrap(void) 
{
	return 1;
}
