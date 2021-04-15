%{
	#include <stdio.h>
	#include "y.tab.h"
	#include <stdlib.h>
	#include "2.header.h"
	int number;
    extern void yyerror();  
%}

%%

[0-9]+		{number = atoi(yytext); yylval.Node = makeLeafNode(number); return NUM;}
[+-]        {yylval.charVal= *yytext; return OP1;}
[*/]        {yylval.charVal= *yytext; return OP2;}
[ \t] 		{}
[()] 		{return *yytext;}
[\n] 		{return NEWLINE;}
.		    {yyerror("unknown character\n");exit(1);}

%%

int yywrap(void) 
{
	return 1;
}
