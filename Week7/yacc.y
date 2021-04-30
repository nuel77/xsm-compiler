%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <ctype.h>
	#include <string.h>
	int yyerror(char const *);   
	extern FILE* yyin;
	#include "codegen.c"
	int yylex(void);
	struct Typetable *curr_type,*Ftype,*Ptype,*Ttype;
	struct Classtable *Ctype;
%}

%union{
    struct tnode* Node;
};

%type <Node>  Body E Slist Stmt InputStmt OutputStmt AsgStmt Returnstmt Ifstmt Whilestmt Breakstmt Continuestmt FieldFunction 
%token NUM START  END  ASSIGN ID READ WRITE IF THEN ELSE ENDIF WHILE DO ENDWHILE BREAK CONTINUE REPEAT UNTIL  DECL ENDDECL INT STR STRING MAIN RETURN
%token TYPE ENDTYPE INITIALIZE ALLOC FREE NIL 
%token CLASS ENDCLASS EXTENDS SELF NEW DELETE
%nonassoc LT GT LE GE NE EQ
%left OR
%left AND
%left PLUS MINUS
%left MUL DIV
%left NOT
%%

program: TypeDefBlock ClassDefBlock GdeclBlock FDefBlock MainBlock  {exit(0);}
	|TypeDefBlock ClassDefBlock GdeclBlock MainBlock				{exit(0);}
	|TypeDefBlock ClassDefBlock MainBlock							{exit(0);}
	|TypeDefBlock ClassDefBlock										{exit(0);}
;
TypeDefBlock: TYPE TypeDefList ENDTYPE				{/*printTypetable();*/}
		|
;
TypeDefList: TypeDefList TypeDef
	|TypeDef
;
TypeDef: ID {TInstall($<Node>1->varname,0,NULL);} '{' FieldDeclList '}'	
	{
	Ttype= TLookup($<Node>1->varname);
	Ttype->fields=Fhead;
	Ttype->size= Typesizeallocator(Ttype);
	Fhead=NULL;
	F_INDEX=0;
	}
;
FieldDeclList: FieldDeclList FieldDecl
	|FieldDecl
;
FieldDecl: TypeName ID ';'	{FInstall(Ttype,$<Node>2->varname);}
;
TypeName: INT		{Ttype = TLookup("Integer");}
	|STR			{Ttype = TLookup("String");}
	|ID 			{Ttype = TLookup($<Node>1->varname);}
;
GdeclBlock: DECL GDecllist ENDDECL  {
									
									initialxsmcode();
									Phead=NULL;
									Lhead=NULL;
									LOCAL_BIND=1;
									PARAM_BIND=1;
                            		}
	|DECL ENDDECL					{initialxsmcode();
									LOCAL_BIND=1;
									PARAM_BIND=1;
									}
;

GDecllist: GDecllist GDec1
	| GDec1
;
GDec1: Type GidList ';'				
;
Type: INT							{curr_type = TLookup("Integer"); Ctype=NULL;}
	|STR							{curr_type = TLookup("String"); Ctype=NULL;}
	|ID	 {
		curr_type = TLookup($<Node>1->varname); 
		Ctype= Clookup($<Node>1->varname);
		if(curr_type==NULL && Ctype==NULL){
			printf("Unknown type:%s",$<Node>1->varname); 
			exit(0);
		}
	}
;
GidList: GidList ',' Gid
	|Gid
;

Gid: ID								{GInstall($<Node>1->varname, curr_type, Ctype, 1, 1, _ID, NULL);}
	|ID '[' NUM ']'					{GInstall($<Node>1->varname, curr_type, NULL, $<Node>3->val, 1, _ARRAY, NULL);}
	|ID '[' NUM ']' '[' NUM ']'		{GInstall($<Node>1->varname, curr_type, NULL, $<Node>3->val, $<Node>6->val, _MATRIX, NULL);}
	|MUL ID
	|ID '(' ParamList ')'			{GInstall($<Node>1->varname, curr_type, NULL, 0, 0, _FUNC, Phead);Phead=NULL; Phead=NULL;}
;
ClassDefBlock: CLASS ClassDefList ENDCLASS{
		//printClasstable();
		struct Classtable *Ctemp= Chead;
		struct Memberfunclist *Mtemp;
		//store all methods of the class into the start of stack
		fprintf(target_file,"L%d:\n", START_FUNC);
		fprintf(target_file, "MOV SP, 4095\n");
		
		while(Ctemp!=NULL){
			CURR_BINDING+=8;
			Mtemp= Ctemp->Vfuncptr;
			int f=0;
			while(Mtemp!=NULL){
				fprintf(target_file, "MOV R0, F%d\n", Mtemp->flabel);
				fprintf(target_file, "PUSH R0\n");
				f++;
				Mtemp=Mtemp->next;
			}
			fprintf(target_file, "MOV R0, -1\n");
			while(f<8){
				fprintf(target_file, "PUSH R0\n");
				f++;
			}
			Ctemp=Ctemp->next;
		}
	}
	|	{fprintf(target_file, "L%d:\n", START_FUNC);}
;
ClassDefList: ClassDefList ClassDef
	| ClassDef
;
ClassDef: Cname '{' DECL Fieldlists MethodDecls ENDDECL MethodDefns '}' {
	struct Fieldlist *Ftemp= Class->Memberfield;
	struct Memberfunclist *Mtemp= Class->Vfuncptr;

	//performing some basic checks for memeory consitency
	int cnt=0;
	while(Ftemp !=NULL){
		Ftemp->fieldIndex= cnt++;
		if(Ftemp->type == NULL)
			cnt++;
		Ftemp= Ftemp->next;
	}
	if(cnt > 8){
		printf("Class member field count cannot exceed 8 %s \n", Class->name);
		exit(0);
	}
	
	cnt= 0;
	while(Mtemp != NULL){
		if(Mtemp->Funcposition == -1){
			printf("Class member Function not defined %s.%s \n",Class->name, Mtemp->name);
			exit(0);
		}
		Mtemp->Funcposition= cnt++;
		Mtemp= Mtemp->next;
	}
	if(cnt > 8){
		printf("Class member function count cannot exceed 8 %s \n", Class->name);
		exit(0);
	}
	Class= NULL;
}
;
Cname: ID {
	CInstall($<Node>1->varname,NULL);
	Class= Clookup($<Node>1->varname);
	}
	| ID EXTENDS ID{

	}
;
Fieldlists: Fieldlists FID
	|FID
;
FID: Type ID ';'{
	//installing memberfield to the class, can be of primitive/userdefined type or a class
	if(curr_type != NULL){
		Class_Finstall(Class,curr_type->name,$<Node>2->varname);
	}
	else if(Ctype!=NULL){
		Class_Finstall(Class,Ctype->name,$<Node>2->varname);
	}
}
;
MethodDecls: MethodDecls MDecl
	|MDecl
;
MDecl: Type ID '(' ParamList ')' ';' 
	{
	//installing methods to the class
	if(Ctype!=NULL){
		printf("Return type of method %s cannot be  a  class \n", $<Node>2->varname);
		exit(0);
	}
	Class_Minstall(Class,$<Node>2->varname,curr_type,Phead);
	Phead= NULL;
	Lhead= NULL;
	LOCAL_BIND=1;
	PARAM_BIND=1;
}
;
MethodDefns: MethodDefns Fdef
	|Fdef
;
FDefBlock: FDefBlock Fdef			
	| Fdef
;
Ftype: INT							{Ftype = TLookup("Integer");}
	|STR							{Ftype = TLookup("String");}
	|ID		{
		Ftype = TLookup($<Node>1->varname); 
		if(Ftype==NULL){
			printf("Unknown type:%s",$<Node>1->varname); 
			exit(0);
		}
	}
;
Fdef: Ftype ID '(' ParamList ')' '{' LdeclBlock Body '}'	{funcdef(Ftype,Class,$<Node>2, Phead,$<Node>8);
														//print_local_declarations(Lhead);
														Phead= NULL;
														Lhead=NULL;
														LOCAL_BIND=1;
														PARAM_BIND=1;
}
;
MainBlock: INT MAIN '(' ')' '{' LdeclBlock Body '}'		{mainfuncdef($<Node>7);
														//print_local_declarations(Lhead);
														Lhead=NULL;
														Phead=NULL;
														LOCAL_BIND=1;
														PARAM_BIND=1;
														}	
;
ParamList: ParamList ',' Param
	| Param 
	|
;
Param: Ptype ID	{
		struct Paramstruct *temp;
		temp= PLookup($<Node>2->varname);
		if(temp!=NULL){
			printf("Multiple declarations for %s in paramlist",$<Node>2->varname);
			exit(0);
		}
		PInstall($<Node>2->varname, Ptype, _ID);
	}
	| MUL Ptype ID		{PInstall($<Node>3->varname, Ptype,_PTR);}
;

Ptype: INT							{Ptype = TLookup("Integer");}
	|STR							{Ptype = TLookup("String");}
	|ID		{
		Ptype = TLookup($<Node>1->varname); 
		if(Ptype==NULL){
			printf("Unknown type:%s",$<Node>1->varname); 
			exit(0);
		}
	}
;
LdeclBlock: DECL LDecList ENDDECL
	| DECL ENDDECL;
	|
;

LDecList: LDecList LDecl
	| LDecl;
;

LDecl: Type IdList ';'
;

IdList: IdList ',' ID		{LInstall($<Node>3->varname, curr_type, _ID);}
	| IdList ',' MUL ID		{LInstall($<Node>4->varname, curr_type, _PTR);}
	| ID					{LInstall($<Node>1->varname, curr_type, _ID);}
	| MUL ID				{LInstall($<Node>2->varname, curr_type, _PTR);}
;

Body: START Slist Returnstmt  END		{$<Node>$= createTree(VAL_NONE, TLookup("void"), "\0", _CONNECTOR, $<Node>2,NULL,$<Node>3);}
	|START Returnstmt END				{$<Node>$= createTree(VAL_NONE, TLookup("void"), "\0", _CONNECTOR, NULL ,NULL,$<Node>2);}
;

Slist: Slist Stmt       {$<Node>$= createTree(VAL_NONE, TLookup("void"), "\0", _CONNECTOR, $<Node>1,NULL,$<Node>2);}
    | Stmt              {$<Node>$= $<Node>1;}
;

Stmt : InputStmt ';'		{$<Node>$=$<Node>1;}
	| OutputStmt ';' 	    {$<Node>$=$<Node>1;}
	| AsgStmt ';'		    {$<Node>$=$<Node>1;}
    | Ifstmt  ';'           {$<Node>$=$<Node>1;}
    | Whilestmt ';'         {$<Node>$=$<Node>1;}
    | Breakstmt  ';'        {$<Node>$=$<Node>1;}
    | Continuestmt ';'      {$<Node>$=$<Node>1;}
	
;
Field: ID '.' ID 	{
	struct Fieldlist *Ftemp= FLookup($<Node>1->type, $<Node>3->varname);
	if(Ftemp == NULL){
		printf("No field name %s in %s \n",$<Node>3->varname,$<Node>1->varname);
		exit(0);
	}
	$<Node>$= createTree(VAL_NONE,  Ftemp->type, "\0", _FIELD, $<Node>1,NULL, createTree(VAL_NONE,TLookup("void"),"\0",_FIELD,$<Node>3,NULL,NULL));
	}

	| Field '.' ID	{
		struct tnode *t1, *t2;
		t2= $<Node>1;
		while(t2->right!=NULL)
			t2= t2->right;
		struct Fieldlist *Ftemp= FLookup($<Node>1->type,$<Node>3->varname);
		if(Ftemp==NULL){
			printf("No Field named %s in %s \n",$<Node>3->varname,t2->left->varname);	
			exit(0);
		}
		t1= createTree(VAL_NONE, TLookup("void"), "\0", _FIELD, $<Node>3,NULL,NULL);
		t2->right= t1;
		$<Node>$= $<Node>1;
		$<Node>$->type= $<Node>3->type;
	}
	| SELF '.' ID {
		if(Class == NULL){
			printf("no class for self found\n");
			exit(0);
		}
		struct Fieldlist *Ftemp= Class_Flookup(Class,$<Node>3->varname);
		if(Ftemp ==NULL){
			printf("no member field named %s in class %s\n",$<Node>3->varname,Class->name);
			exit(0);
		}
		$<Node>$= createTree(VAL_NONE,Ftemp->type,Class->name,_FIELD,$<Node>3,NULL,NULL);
	}
;
FieldFunction: ID '.' ID '(' ArgList ')' {
	struct Gsymbol *Gtemp;
	Gtemp= GLookup($<Node>1->varname);
	if(Gtemp==NULL){
		printf("unkown identifier %s\n",$<Node>1->varname);
		exit(0);
	}
	if(Class!=NULL){
		printf("self should be used inside class definition\n");
		exit(0);
	}
	if($<Node>1->Gentry->Ctype ==NULL){
		printf("method %s can be called only by an object\n",$<Node>3->varname);
		exit(0);
	}
	struct Memberfunclist *Mtemp= Class_Mlookup(Gtemp->Ctype,$<Node>3->varname);
	if(Mtemp ==NULL){
		printf("no method called %s in class %s",$<Node>3->varname,Class->name);
		exit(0);
	}
	$<Node>$= createTree(VAL_NONE,Mtemp->type,"\0",_METHOD1,$<Node>1,$<Node>3,$<Node>5);
	}

	| SELF '.' ID '(' ArgList ')' {
		if(Class ==NULL){
			printf("self cannot be used outside class definition\n");
			exit(0);
		}
		struct Memberfunclist *Mtemp= Class_Mlookup(Class,$<Node>3->varname);
		if(Mtemp == NULL){
			printf("no method called %s in class %s",$<Node>3->varname,Class->name);
			exit(0);
		}
		$<Node>$= createTree(VAL_NONE,Mtemp->type,Class->name,_METHOD2,$<Node>3,NULL,$<Node>5);
	}
	
	| Field '.' ID '(' ArgList ')' {
		struct Fieldlist *Ftemp= Class_Flookup(Class,$<Node>1->left->varname);
		struct Memberfunclist *Mtemp= Class_Mlookup(Ftemp->Ctype,$<Node>3->varname);
		if(Mtemp == NULL){
			printf("no method named %s in class %s *\n",$<Node>3->varname,$<Node>1->varname);
			exit(0);
		}
		$<Node>$= createTree(VAL_NONE,Mtemp->type,"\0",_METHOD3,$<Node>1,$<Node>3,$<Node>5);
	}
;
InputStmt: READ '(' ID ')'      		{$<Node>$= createTree(VAL_NONE, TLookup("void"), "\0", _READ, $<Node>3,NULL,NULL);}
		| READ '(' ID '[' E ']' ')'		{$<Node>$ = createTree(VAL_NONE, TLookup("void"), "\0", _READ_ARRAY, $<Node>3, $<Node>5, NULL);}
		| READ '(' Field ')'			{$<Node>$ = createTree(VAL_NONE,TLookup("void"),"\0",_READ_FIELD,$<Node>3,NULL,NULL);}
;

OutputStmt: WRITE '(' E ')'     {$<Node>$= createTree(VAL_NONE, TLookup("void"), "\0", _WRITE, $<Node>3,NULL,NULL);}
;

AsgStmt: ID ASSIGN E            	{$<Node>$=  createTree(VAL_NONE, TLookup("void"), "\0", _ASSIGN, $<Node>1,NULL,$<Node>3);}
	| ID '[' E ']' ASSIGN E			{$<Node>$ = createTree(VAL_NONE, TLookup("void"), "\0", _ASGN_ARRAY,$<Node>1, $<Node>3, $<Node>6);}
	| ID ASSIGN INITIALIZE '(' ')'	{$<Node>$ = createTree(VAL_NONE,TLookup("void"),"\0",_ASSIGN,$<Node>1,NULL, createTree(VAL_NONE,TLookup("Integer"),"\0",_INIT,NULL,NULL,NULL));}
	| ID ASSIGN ALLOC '(' ')'		{$<Node>$ = createTree(VAL_NONE,TLookup("void"),"\0",_ASSIGN,$<Node>1,NULL, createTree(VAL_NONE,TLookup("Type"),"\0",_ALLOC,NULL,NULL,NULL));}
	| Field ASSIGN E				{$<Node>$ = createTree(VAL_NONE,TLookup("void"),"\0",_ASSIGN_FIELD,$<Node>1,NULL,$<Node>3);}
	| Field ASSIGN ALLOC '(' ')'	{$<Node>$ = createTree(VAL_NONE,TLookup("void"),"\0",_ASSIGN_FIELD,$<Node>1,NULL, createTree(VAL_NONE,TLookup("Type"),"\0",_ALLOC,NULL,NULL,NULL));}
	| FREE '(' ID ')'				{$<Node>$ = createTree(VAL_NONE,TLookup("void"),"\0",_FREE,$<Node>3,NULL,NULL);}
	| FREE '(' Field ')'			{$<Node>$ = createTree(VAL_NONE,TLookup("void"),"\0",_FREE,$<Node>3,NULL,NULL);}
	| ID ASSIGN NEW '(' ID ')'		{$<Node>$ = createTree(VAL_NONE,TLookup("void"),"\0",_ASSIGN,$<Node>1,$<Node>5,createTree(VAL_NONE,TLookup("Type"),"\0",_ALLOC,NULL,NULL,NULL));}
	| Field ASSIGN NEW '(' ID ')'	{$$ = createTree(VAL_NONE,TLookup("void"),"\0",_ASSIGN_FIELD,$<Node>1,$<Node>5,createTree(VAL_NONE,TLookup("Type"),"\0",_ALLOC,NULL,NULL,NULL));}
	| DELETE '(' Field ')'			{$$ = createTree(VAL_NONE,TLookup("void"),"\0",_FREE,$<Node>3,NULL,NULL);}
;
;

Ifstmt: IF '(' E ')' THEN Slist ELSE Slist ENDIF    {$<Node>$= createTree(VAL_NONE, TLookup("void"), "\0", _IF_THEN_ELSE, $<Node>3,$<Node>6,$<Node>8);}
    | IF '(' E ')' THEN Slist ENDIF                 {$<Node>$= createTree(VAL_NONE, TLookup("void"), "\0", _IF_THEN, $<Node>3, $<Node>6, NULL);}
;
Whilestmt: WHILE '(' E ')' DO Slist ENDWHILE        {$<Node>$= createTree(VAL_NONE, TLookup("void"), "\0", _WHILE, $<Node>3, $<Node>6 ,NULL);}
    | REPEAT Slist UNTIL '(' E ')'                  {$<Node>$= createTree(VAL_NONE, TLookup("void"), "\0", _REAPEAT_UNTIL, $<Node>5, $<Node>2, NULL);}
    | DO Slist WHILE '(' E ')'                      {$<Node>$= createTree(VAL_NONE, TLookup("void"), "\0", _DO_WHILE, $<Node>5, $<Node>2, NULL);} 
;

Continuestmt: CONTINUE                              {$<Node>$= createTree(VAL_NONE, TLookup("void"), "\0", _CONTINUE, NULL, NULL, NULL);}
;

Breakstmt: BREAK                                    {$<Node>$= createTree(VAL_NONE, TLookup("void"), "\0", _BREAK, NULL, NULL, NULL);}
;

Returnstmt: RETURN E ';'							{$<Node>$= createTree(VAL_NONE, TLookup("void"), "\0", _RET, $<Node>2, NULL, NULL);}
;

ArgList: ArgList ',' E								{$<Node>$= createTree(VAL_NONE,TLookup("void"), "\0", _ARG,  $<Node>1, NULL, $<Node>3);}
	| E												{$<Node>$= createTree(VAL_NONE, TLookup("void"), "\0", _ARG, NULL, NULL, $<Node>1);}
	|												{$<Node>$=NULL;}
;

E 	: E PLUS E 		{$<Node>$ = createTree(VAL_NONE, TLookup("Integer"), "\0", _PLUS, $<Node>1, NULL, $<Node>3);}
	| E MINUS E 	{$<Node>$ = createTree(VAL_NONE, TLookup("Integer"), "\0", _MINUS, $<Node>1, NULL, $<Node>3);}
	| E MUL E 		{$<Node>$ = createTree(VAL_NONE, TLookup("Integer"), "\0", _MUL, $<Node>1, NULL, $<Node>3);}
	| E DIV E 		{$<Node>$ = createTree(VAL_NONE, TLookup("Integer"), "\0", _DIV, $<Node>1, NULL, $<Node>3);}
	| '(' E ')' 	{$<Node>$ = $<Node>2;}
	| E EQ E 		{$<Node>$ = createTree(VAL_NONE, TLookup("Boolean"), "\0", _EQ, $<Node>1, NULL, $<Node>3);}
	| E NE E 		{$<Node>$ = createTree(VAL_NONE, TLookup("Boolean"), "\0", _NE, $<Node>1, NULL, $<Node>3);}
	| E LE E		{$<Node>$ = createTree(VAL_NONE, TLookup("Boolean"), "\0", _LE, $<Node>1, NULL, $<Node>3);}
	| E GE E 		{$<Node>$ = createTree(VAL_NONE, TLookup("Boolean"), "\0", _GE, $<Node>1, NULL, $<Node>3);}
	| E LT E 		{$<Node>$ = createTree(VAL_NONE, TLookup("Boolean"), "\0", _LT, $<Node>1, NULL, $<Node>3);}
	| E GT E  		{$<Node>$ = createTree(VAL_NONE, TLookup("Boolean"), "\0", _GT, $<Node>1, NULL, $<Node>3);}
	| NUM 			{$<Node>$ = $<Node>1;}
	| STRING		{$<Node>$ = $<Node>1;}	
	| NIL 			{$<Node>$ = createTree(VAL_NONE,TLookup("Type"), "\0", _NULL, NULL, NULL, NULL);}	
	| Field			{$<Node>$ = $<Node>1;}
	| FieldFunction {$<Node>$ = $<Node>1;}
	| ID			{$<Node>$ = $<Node>1;}
	| ID '[' E ']'	{$<Node>$ = createTree(VAL_NONE, $<Node>1->type, $<Node>1->varname, _ARRAY, $<Node>1, $<Node>3, NULL);}
	| ID '(' ArgList ')' {$<Node>$= createTree(VAL_NONE, $<Node>1->type, $<Node>1->varname, _FUNC, $<Node>1, NULL, $<Node>3);}

;

%%
int yyerror(char const *s){
	printf("yyerror %s\n",s);
}

int main(int argc, char *argv[]) 
{	
	
	FILE *fp = fopen(argv[1],"r");
	if(fp)
		yyin=fp;
	START_FUNC=get_label();
	target_file=fopen("target.xsm","w");	
	fprintf(target_file, "0\n2056\n0\n0\n0\n0\n0\n0\n");
	fprintf(target_file, "JMP L%d\n", START_FUNC);
	TypeTableCreate();
	yyparse();
	return 0;
}