%{
    #include<stdio.h>
    #include<stdlib.h>
    #include"1.header.h"
    extern int yylex(void);
    void yyerror();
%}
%union{
    struct tnode* Node;
    char charVal;
    int intVal;
};
%token NEWLINE VAR
%left OP1
%left OP2

%%
program: expr NEWLINE   {
                        int ans=evaluate($<Node>1);
                        printf("\nans is %d \n",ans);
                        postfix($<Node>1); printf("\n");
                        prefix($<Node>1);  printf("\n");
                        exit(1);
                        }
;

expr:expr OP1 expr      {$<Node>$= makeOperatorNode($<Node>1,$<charVal>2,$<Node>3);}
    |expr OP2 expr      {$<Node>$= makeOperatorNode($<Node>1,$<charVal>2,$<Node>3);}
    |'(' expr ')'       {$<Node>$= $<Node>2;}
    |VAR                {$<Node>$=makeLeafNode($<intVal>1);
}
%%
void yyerror(){
    printf("error occurred\n");
}
int main(){
    yyparse();
	return 0;
}