%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <ctype.h>
	#include <string.h>
	
    int CurrPass, CurrLineNo, CurrAddr;
    char* CurrLabel;
    FILE* target_file;

    struct label_table{
        char * label;
        int address;
        struct label_table *next;
    };

    struct label_table *HEAD=NULL;
    void push_label(char *,int);
    int get_address(char*);
%}

%%
[a-zA-Z][0-9]+[:][\n]   {

    if(CurrPass== 1){
        CurrLabel= (char*)malloc( sizeof(char) * (yyleng-2) );
        yyless(yyleng-2);
        CurrLabel= strdup(yytext);
        push_label(CurrLabel, CurrLineNo);
        CurrLineNo-=2;
    }
} 

"JMP "[a-zA-Z][0-9]+    {
    if(CurrPass==2){
        fprintf(target_file,"JMP %d", get_address(yytext+4));
    }
}

"JZ R"[0-9]+[,][ ][a-zA-Z][0-9]+    {
    if(CurrPass==2){
        if(isdigit(yytext[5]))
			fprintf(target_file, "JZ R%c%c, %d", yytext[4], yytext[5], get_address(yytext+8));
		else
			fprintf(target_file, "JZ R%c, %d", yytext[4],get_address(yytext+7));
    }
}

"JNZ R"[0-9]+[,][ ][a-zA-Z][0-9]+ {
    if(CurrPass==2){
        if(isdigit(yytext[6]))
            fprintf(target_file, "JNZ R%c%c, %d", yytext[5], yytext[6], get_address(yytext+9));
        else 
           fprintf(target_file, "JNZ R%c, %d", yytext[5], get_address(yytext+8)); 
    }
}


"CALL 0"    {
    if(CurrPass==2)
        fprintf(target_file, "CALL 0");
}
"CALL "[a-zA-Z][a-zA-Z0-9]+ {
    if(CurrPass==2)
        fprintf(target_file, "CALL %d", get_address(yytext+5));
}

"\n"    {
    if(CurrPass==2)
        fprintf(target_file, "\n");
    else {
        if(CurrLineNo < 2056) CurrLineNo++;
        else CurrLineNo+=2;
    }
}	
.   {
    if(CurrPass==2)
        fprintf(target_file, "%s", yytext);
}			
				

%%
int get_address(char *label){
    struct label_table *temp= (struct label_table*)malloc(sizeof(struct label_table));
    temp= HEAD;
    while(temp!=NULL){
        if(strcmp(temp->label,label)==0) return temp->address;
        temp=temp->next;
    }
    return -1;
}
void push_label(char *label,int address){
    struct label_table *temp= (struct label_table*)malloc(sizeof(struct label_table));
    temp->label= label;
    temp->address= address;
    temp->next=NULL;

    if(HEAD==NULL){
        HEAD=temp;
    }
    else{
        temp->next= HEAD;
        HEAD= temp;
    }

}
int yywrap(void){
    if(CurrPass==1){
        yyin= fopen("target.xsm","r");
        CurrPass++;
        return 0;
    }
    else{
        return 1;
    }
}

int main(){
    CurrPass= 1;
    CurrLineNo= 2048;

    target_file= fopen("translated.xsm","w");
    yyin= fopen("target.xsm","r");
    yylex();
    fclose(target_file);
    fclose(yyin);
    return 1;
}