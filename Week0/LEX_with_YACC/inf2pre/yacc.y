%{
    #include<stdio.h>
    #include<stdlib.h>
    #include<string.h> 
    void yyerror();
    extern int yylex();

    char *make_prefix(const char*,const char*,const char*);
%}
%union{
    char * String;
};

%token VAR NEWLINE
%left OP1
%left OP2
%start START

%%

START: expr NEWLINE { printf("%s \n",$<String>1); exit(1);}
;

expr: expr OP1 expr     {$<String>$= make_prefix($<String>1,$<String>2,$<String>3);}
    | expr OP2 expr     {$<String>$= make_prefix($<String>1,$<String>2,$<String>3);}
    | '(' expr ')'      {$<String>$= $<String>2;}
    | VAR               {$<String>$= $<String>1;}
;
%%
char *make_prefix(const char* var1,const char* op,const char* var2)
{
    int n= strlen(var1)+ strlen(op)+ strlen(var2)+1;
    char *res= malloc(sizeof(char) * n);
    int idx=0;

    for(int i=0; i<strlen(op); i++)
        res[idx++]= op[i];
    for(int i=0; i<strlen(var1);i++)
        res[idx++]= var1[i];
    for(int i=0;i<strlen(var2); i++)
        res[idx++]=var2[i];
    res[idx]='\0';
    
    // printf("--debug %s \n",res);
    return res;
}
void yyerror(){
    printf("\nError\n");
}
int main()
{
    yyparse();
    return 1;
}