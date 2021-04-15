%{
    #include<stdio.h>
    #include<stdlib.h>
    #include"1.header.h"
    #include"y.tab.h"
%}
%%
[0-9]+  {yylval.intVal=atoi(yytext); return VAR;}
[+-]    {yylval.charVal=*yytext; return OP1;}
[*/]    {yylval.charVal=*yytext; return OP2;}
\n      {return NEWLINE;}	
%%
int yywrap(void){
	return 1;
}
