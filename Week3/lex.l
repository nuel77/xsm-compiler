%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "header.h"
    #include "y.tab.h"
    extern int yyerror(char const *);

	int number;
	char varname;

%}

%%

"begin"		{return START;}

"end"		{return END;}

"read"		{return READ;}

"write"		{return WRITE;}

"if"		{return IF;}

"then"		{return THEN;}

"else"		{return ELSE;}

"endif"		{return ENDIF;}

"while"		{return WHILE;}

"do"		{return DO;}

"endwhile"	{return ENDWHILE;}

"break"		{return BREAK;}

"continue"	{return CONTINUE;}

"repeat"	{return REPEAT;}

"until"		{return UNTIL;}



[a-z]		{
			varname = *yytext;
			yylval.Node = createTree(VAL_NONE, _inttype, varname, _ID, NULL, NULL, NULL);
			return ID;
		}


[0-9]+ 		{
			number = atoi(yytext); 
			yylval.Node = createTree(number, _inttype, VARNAME_NONE, _NUM, NULL, NULL, NULL);
			return NUM;
		}

"="			{return ASSIGN;}
"+" 		{return PLUS;}
"-" 		{return MINUS;}
"*" 		{return MUL;}
"/" 		{return DIV;}
"<"			{return LT;}
">"			{return GT;}
"<="		{return LE;}
">="		{return GE;}
"!="		{return NE;}
"=="		{return EQ;}

[\n \t] 	{}

[{}()] 		{return *yytext;}

[&.,;\"]	{return *yytext;}

.		{yyerror("unknown character\n");exit(1);}

%%

int yywrap(void) 
{
	return 1;
}
