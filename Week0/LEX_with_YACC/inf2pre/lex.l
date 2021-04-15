%{
    #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>
    #include"y.tab.h"

%}

%%

[a-zA-Z]+   { yylval.String = strdup(yytext); return VAR;   }
[+-]        { yylval.String = strdup(yytext);  return OP1;  }
[/*]        { yylval.String = strdup(yytext);  return OP2;  }
[()]        { return *yytext; }
\n        { return NEWLINE; }
.           {;}
%%

int yywrap(){
    return 1;
}