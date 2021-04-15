%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "header.h"
    #include "y.tab.h"
	#include <string.h>
	#include<ctype.h>
    int yyerror(char const *);
	int number;
	char * varname;
	char * curr_str;

%}

%%

"begin"		{return START;}

"end"		{return END;}

"read"		{return READ;}

"main"		{return MAIN;}

"return"	{return RETURN;}

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

"decl"		{return DECL;}

"enddecl"	{return ENDDECL;}

"int"		{return INT;}

"str"		{return STR;}


[a-zA-Z][a-zA-Z0-9]*	{
		varname = strdup(yytext);
		yylval.Node = createTree(VAL_NONE, _inttype, varname, _ID, NULL, NULL, NULL);
		return ID;
}


[0-9]+ 	{
		number = atoi(yytext);
		yylval.Node = createTree(number, _inttype, "\0", _NUM, NULL, NULL, NULL);
		return NUM;
}
		
["][ a-zA-Z0-9]+["]	{
		curr_str=strdup(yytext+1);	//removes the first "
		curr_str[yyleng-2]='\0';	//replaces the last "
		yylval.Node = createTree(VAL_NONE, _strtype, curr_str, _STR, NULL, NULL, NULL);
		return STRING;
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
"["    		{return *yytext;}
"]"			{return *yytext;}	

[\n \t] 	{}

[{}()] 		{return *yytext;}

[&.,\":;]	{return *yytext;}

.		{yyerror("unknown character\n");exit(1);}

%%

int yywrap(void) 
{
	return 1;
}
