#include "header.h"

int get_label(){
    return LABEL_COUNT++;
}
int get_register(){
    
    if(REG_COUNT>=20){
        printf("Out of Registers!\n");
        exit(1);
    }
    else 
        ++REG_COUNT;
        // printf("reg count inc: %d\n", REG_COUNT);
        return REG_COUNT;
}
void free_register(){
   if(REG_COUNT>=0)
		REG_COUNT--;
}

int next_label(){
    return LABEL_COUNT++;
}

int getFlabel(){
	return flabel++;
}
int GetSize(struct Typetable *type){
	if(type!=NULL)
		return type->size;
	else
		return -1;
}
void TypeTableCreate(){
    // printf("inside fcn typtablecreate\n");
    TInstall("Integer",1,NULL);
    TInstall("String",1,NULL);
    TInstall("Boolean",0,NULL);
    TInstall("Null",0,NULL);
    TInstall("Void",0,NULL);
	TInstall("Type",0,NULL);
}

void push_to_LL(int brk,int cnt){
    struct loop_label_node *temp= (struct loop_label_node *)malloc(sizeof(struct loop_label_node));
    temp->brk= brk;
    temp->cnt= cnt;
    temp->next= loop_head;
}

void pop_from_LL(){
    if(loop_head==NULL) return ;
    struct loop_label_node*temp= loop_head;
    loop_head= loop_head->next;
    free(temp);
}

struct Memberfunclist * Class_Mlookup(struct Classtable* ctype, char*name){
    struct Memberfunclist *Mtemp= ctype->Vfuncptr;
    while(Mtemp!=NULL){
        if(strcmp(Mtemp->name,name)==0)
            return Mtemp;
        Mtemp=Mtemp->next;
    }
    return NULL;
}
struct Fieldlist* Class_Flookup(struct Classtable *ctype, char*name){
    struct Fieldlist *Ftemp= ctype->Memberfield;
    while(Ftemp!=NULL){
        if(strcmp(Ftemp->name,name)==0)
            return Ftemp;
        Ftemp= Ftemp->next;
    }
    return NULL;
}

struct Classtable* Clookup(char *name){
    struct Classtable* Ctemp= Chead;
    while(Ctemp!=NULL){
        if(strcmp(Ctemp->name,name)==0)
            return Ctemp;
        Ctemp= Ctemp->next;
    }
    return NULL;
}
struct Fieldlist* FLookup(struct Typetable *type, char *name){
    struct Fieldlist* curr= type->fields;
    while(curr!=NULL){
        if(strcmp(curr->name,name)==0) return curr;
        curr=curr->next;
    }
    return NULL;
}
struct Typetable *TLookup(char *name){
    struct Typetable *curr=Thead;
    while(curr!=NULL){
       
        if(strcmp(curr->name,name)==0){
            return curr;
        }
        curr= curr->next;
    }
    
    return NULL;
}
struct Gsymbol* GLookup(char *name){
    struct Gsymbol *curr= Ghead;

    while(curr != NULL){
        if(strcmp(curr->name, name)==0)
            return curr;
        curr= curr->next;
    }
    return NULL;
}
struct Lsymbol* LLookup(char *name ){
    struct Lsymbol *curr= Lhead;
    while(curr != NULL){
        if(strcmp(curr->name, name)==0)
            return curr;
        curr= curr->next;
    }
    return NULL;
}
struct Paramstruct *PLookup(char *name){
    struct Paramstruct *curr= Phead;
    while(curr!=NULL){
        if(strcmp(curr->name,name)==0)
            return curr;
        curr= curr->next;
    }
    return NULL;
}
void Class_Minstall(struct Classtable* cptr,char *name, struct Typetable *type, struct Paramstruct *paramlist){
    struct Memberfunclist *Mtemp,*Mtemp_last;
    struct Paramstruct *Ptemp1,*Ptemp2;
    Mtemp= cptr->Vfuncptr;
    
    int flag=0;
    while(Mtemp !=NULL){
        
        if(strcmp(Mtemp->name,name)==0){
            Ptemp1= Mtemp->paramlist;
            Ptemp2= paramlist;
            flag= check_equivalence(Ptemp1,Ptemp2);
            if(flag==0){
                Mtemp->Funcposition=-1;
                Mtemp->flabel= getFlabel();
                return ;
            }
            else{
                printf("multiple methods by same name : %s \n",name);
                exit(0);
            }
        }
        Mtemp_last=Mtemp;
        Mtemp= Mtemp->next;
    }
    
    Mtemp=malloc(sizeof(struct Memberfunclist));
	Mtemp->name=malloc(sizeof(name));
	strcpy(Mtemp->name,name);
	Mtemp->type=type;
	Mtemp->paramlist=paramlist;
	Mtemp->Funcposition=-1;
	Mtemp->flabel=getFlabel();
	Mtemp->next=NULL;
    cptr->Methodcount++;

    if(cptr->Vfuncptr==NULL){
        cptr->Vfuncptr= Mtemp;
    }
    else
        Mtemp_last->next= Mtemp;

}
void Class_Finstall(struct Classtable* cptr, char * typename, char* name){
    struct Typetable *type= TLookup(typename);
    struct Classtable *ctype= Clookup(typename);
    if(type==NULL && ctype==NULL){
        printf("type cannot for installed for field %s \n",name);
        exit(0);
    }
    struct Fieldlist *Ftemp,*Ftemp_last;
    Ftemp= cptr->Memberfield;
    // printf("fields present are: ");
    while(Ftemp!=NULL){
        // printf("%s -> ",Ftemp->name);
        if(strcmp(Ftemp->name,name)==0){
            printf("multiple field by the same name %s \n",name);
            exit(0);
        }
        Ftemp_last=Ftemp;
        Ftemp= Ftemp->next;
    }
    // printf("\n");
    Ftemp=malloc(sizeof(struct Fieldlist));
	Ftemp->name=malloc(sizeof(name));
	strcpy(Ftemp->name,name);
	Ftemp->fieldIndex = F_INDEX++;
	Ftemp->type=type;
	Ftemp->Ctype= ctype;
	Ftemp->next=NULL;

    cptr->Fieldcount++;
    if(cptr->Memberfield==NULL){
        cptr->Memberfield= Ftemp;
    }
    else
        Ftemp_last->next= Ftemp;
}
void CInstall(char *name, char *parent_class_name){

    struct Typetable *Ttemp;
    Ttemp= TLookup(name);
    if(Ttemp!= NULL){
        printf("class and user defined type have same name\n");
        exit(0);
    }
    struct Classtable *Ctemp,*Ctemp_par;
    Ctemp= Clookup(name);
    if(Ctemp!=NULL){
        printf("definition for class %s already exits\n", name);
        exit(0);
    }
    Ctemp= (struct Classtable*)malloc(sizeof(struct Classtable));
    Ctemp->name= malloc(sizeof(name));

    strcpy(Ctemp->name,name);
    Ctemp->Memberfield = NULL;
	Ctemp->Vfuncptr = NULL;
	Ctemp->Parentptr = NULL;
	Ctemp->class_idx = C_INDEX++;
	Ctemp->Fieldcount = 0;
	Ctemp->Methodcount = 0;
	Ctemp->next = NULL;
    
    if(parent_class_name!=NULL){
        Ctemp_par= Clookup(parent_class_name);
        if(Ctemp_par==NULL){
            printf("parent class %s for inheritance does not exit\n",parent_class_name);
            exit(0);
        }
        Ctemp->Parentptr= Ctemp_par;
    }
    if(Chead ==NULL){
        Chead= Ctemp;
    }
    else{
        struct Classtable* curr= Chead;
        while(curr->next!= NULL) curr= curr->next;
        curr->next= Ctemp;
    }
}
void FInstall(struct Typetable *type,char *name){
    if(type ==NULL){
        printf("type is null so %s not installed\n",name);
        exit(0);
    }
    struct Fieldlist *temp, *curr = Fhead;
    while(curr!=NULL){
        if(strcmp(curr->name,name)==0){
            printf("multiple fields by name %s\n",name);
            exit(0);
        }
        curr=curr->next;
    }
    temp= malloc(sizeof(struct Fieldlist));
    temp->name= malloc(sizeof(name));
    strcpy(temp->name,name);
    temp->fieldIndex= F_INDEX++;
    temp->type= type;
    temp->next= NULL;
    if(Fhead==NULL){
        Fhead= temp;
    }
    else{
        curr=Fhead;
        while(curr->next!=NULL) curr=curr->next;
        curr->next= temp;
    }
}

void TInstall(char *name, int size, struct Fieldlist *fields){
    // printf("Tinstall called : %s\n",name);
    struct Typetable *temp;
    temp= TLookup(name);
   
    if(temp !=NULL){
        printf("Type %s already exist(Tinstall)\n",name);
        exit(0);
    }
    temp= malloc(sizeof(struct Typetable));
    temp->name= malloc(sizeof(name));
    strcpy(temp->name,name);
    temp->size= size;
    temp->fields= fields;
    temp->next= NULL;
    if(Thead == NULL){
        Thead=temp;
    }
    else{
        struct Typetable *curr= Thead;
        while(curr->next!=NULL) curr=curr->next;
        curr->next=temp;
    }
}

void GInstall(char *name, struct Typetable *type, struct Classtable *Ctype, int size1, int size2, enum NodeType nodetype, struct Paramstruct *paramlist){
    struct Gsymbol *tmp;
    tmp= GLookup(name);
    if(tmp!=NULL){
        printf("Same variable name already declared! %s\n",name);
        exit(0);
    }
    if(CURR_BINDING + size1*size2> 5120){
        printf("Stack overflow\n");
        exit(0);
    }
    tmp = (struct Gsymbol*) malloc(sizeof(struct Gsymbol));
    tmp->name= malloc(sizeof(name));
    strcpy(tmp->name,name);

    tmp->type= type;
    tmp->Ctype=Ctype;
    tmp->size1= size1;
    if(Ctype!=NULL)
        tmp->size1= 2;
    tmp->size2= size2;
    tmp->nodetype= nodetype;
    
    tmp->paramlist= paramlist;
    tmp->next= NULL;
    
    if(tmp->nodetype == _FUNC){
        tmp->flabel= getFlabel();
        tmp->binding= -1;
    }
    else{
        tmp->flabel=-1;
        tmp->binding= CURR_BINDING;
    }
    
    CURR_BINDING += tmp->size1*tmp->size2;
    if(Ghead==NULL){
        Ghead= tmp;
    }
    else{
        tmp->next= Ghead;
        Ghead= tmp;
    }
}

void LInstall(char *name, struct Typetable *type, enum NodeType nodetype){
    struct Lsymbol *temp,*curr;
    curr= Lhead;
    temp= LLookup(name);
    if(temp!= NULL){
        printf("multiple declration of %s", name);
        exit(0);
    }
    temp= malloc(sizeof(struct Lsymbol));
    temp->name= malloc(sizeof(name));
    strcpy(temp->name,name);
    temp->type= type;
    temp-> nodetype= nodetype;
    temp->binding= LOCAL_BIND++;
    temp->next= NULL;

   
    if(curr==NULL){
        Lhead=temp;
    }
    else{
        while(curr->next!=NULL) curr= curr->next;
        curr->next= temp;
    }
}

void PInstall(char* name, struct Typetable *type, enum NodeType nodetype){

    struct Paramstruct *temp;
    struct Paramstruct *curr;
     
    curr= Phead;

    temp= PLookup(name);
   
    if(temp!=NULL){
        printf("multiple declarations : %s \n",name);
        exit(1);
    }
   
    temp= malloc(sizeof(struct Paramstruct));
    temp->name= malloc(sizeof(name));
    strcpy(temp->name, name);

    temp->type= type;
    temp->nodetype= nodetype;
    temp->binding= PARAM_BIND++;
    temp->next= NULL;
    if(Phead == NULL){
        Phead= temp;
    }
    else {
        while(curr->next!= NULL) curr= curr->next;
        curr->next= temp;
    }
   
}
struct tnode * createTree(int val,  struct Typetable *type, char *varname, enum NodeType nodetype, struct tnode* left, struct tnode* mid, struct tnode* right){

    struct tnode *temp;
    temp= (struct tnode*)malloc(sizeof(struct tnode));

    struct Lsymbol *L=NULL;
    struct Gsymbol *g ;
    struct Paramstruct *P=NULL;

    temp->val= val;
    temp->type= type;
    temp->nodetype= nodetype;
    temp->varname=malloc(sizeof(varname));
    strcpy(temp->varname, varname);

    

    switch(nodetype){
        case _ID:
        case _PTR:
        case _ADDR:
            L= LLookup(temp->varname); //<--fix here
            P= PLookup(temp->varname); //<--fix here
            g= GLookup(temp->varname);
            if(L!= NULL){
                temp->type= L->type;
            }
            else if(P!= NULL){
                temp->type= P->type;
            }
            else if(g!= NULL){
                temp->type= g->type;
            }
            temp->Lentry = L;
            temp->Gentry = g;
            break;

        case _ARRAY:
        case _MATRIX:
            g= GLookup(temp->varname);
            if(g!=NULL){
                temp->type= g->type;
            }
            temp->Lentry=L;
			temp->Gentry=g;
            break;
    }
    
    temp->left=left;
    temp->mid= mid;
    temp->right=right;

    if(type_guard(temp)){
        return temp;
    }
    else {
        printf("Now exiting\n");
        exit(1);
    }
    
}
void mainfuncdef(struct tnode *body){
    struct Lsymbol *Ltemp;
    fprintf(target_file,"MAIN:\n");
    fprintf(target_file,"PUSH BP\n");
    fprintf(target_file,"MOV BP, SP\n");
    
    int LVarCount=0;
	for(Ltemp=Lhead; Ltemp!=NULL; Ltemp=Ltemp->next){
		LVarCount++;
    }
	fprintf(target_file,"ADD SP, %d\n",LVarCount);	//Pushing Local Variable
    codeGen(body);
}
void funcdef(struct Typetable *type, struct Classtable *Ctype, struct tnode *func, struct Paramstruct *Phead, struct tnode * body){

    if(body->right->left->type!=type){
		printf("Return type of Function %s not correct\n",getFunctionname(F_INDEX-1));
		exit(0);
	}
    int flag;
    struct Lsymbol *Ltemp;
    struct Gsymbol *Gtemp;
    struct Paramstruct *Pdef, *Pdecl;
    struct Memberfunclist *Mtemp;
    if(Ctype!= NULL){
       // printf("func def enocutnered\n");
        Mtemp= Ctype->Vfuncptr;
        while(Mtemp!=NULL){
            if(!strcmp(func->varname,Mtemp->name)){
                Pdef= Phead;
                Pdecl= Mtemp->paramlist;
                flag= check_equivalence(Pdef,Pdecl);
                if(flag ==-1){
                    printf("formal parameters and declarations are not matching for method %s\n",func->varname);
                    exit(0);
                }
                else{
                    break;
                }
            }
            Mtemp= Mtemp->next;
        }

        if(Mtemp ==NULL){
            printf("method not declared %s \n",func->varname);
            exit(0);
        }
        Mtemp->Funcposition=0;
        fprintf(target_file, "F%d:\n", Mtemp->flabel);
		fprintf(target_file, "PUSH BP\n");
		fprintf(target_file, "MOV BP, SP\n");

        int lVarCount=0;
        for(Ltemp=Lhead; Ltemp!=NULL; Ltemp= Ltemp->next)
            lVarCount++;
        fprintf(target_file,"ADD SP, %d\n",lVarCount);
        codeGen(body);
    }
    else{
        Gtemp= GLookup(func->varname);
        if(Gtemp==NULL || Gtemp->nodetype!=_FUNC){
            printf("function not declared %s \n",func->varname);
            exit(0);
        }
        if(Gtemp->type!=type){
            printf("return type does not match in function %s\n",func->varname);
            exit(0);
        }
        
        Pdecl= Gtemp->paramlist;
        Pdef= Phead;

        flag= check_equivalence(Pdecl,Pdef);
        if(flag==-1){
            printf("Parameters doesn not match with declaration in function %s\n",func->varname);
            exit(0);
        }
        fprintf(target_file,"F%d:\n",Gtemp->flabel);
        fprintf(target_file,"PUSH BP\n");
        fprintf(target_file,"MOV BP, SP\n");

        int lVarCount=0;
        for(Ltemp= Lhead; Ltemp!=NULL; Ltemp=Ltemp->next)
            lVarCount++;
        
        fprintf(target_file,"ADD SP, %d\n", lVarCount);
        codeGen(body);
    }
}

char *printvartype(int nodetype){
	if(nodetype==_ID)
		return strdup("ID");
	else if(nodetype==_ARRAY)
		return strdup("ARRAY");
	else if(nodetype==_MATRIX)
		return strdup("MATRIX");
	else if(nodetype==_PTR)
		return strdup("POINTER");
	else if(nodetype==_FUNC)
		return strdup("FUNCTION");
	else
		return strdup("OTHER");
}

void printClasstable(){
    struct Classtable *Ctemp= Chead;
    while(Ctemp!=NULL){
        printf("**********************\n");
		printf("Class name : %s\n",Ctemp->name);
		if(Ctemp->Parentptr!=NULL)
			printf("Parent Class : %s\n",Ctemp->Parentptr->name);
		else
			printf("Parent Class name : NULL\n");
		printf("Class index : %d\n",Ctemp->class_idx);
		printf("Field count : %d\n",Ctemp->Fieldcount);
		printf("Method count : %d\n",Ctemp->Methodcount);
		printField2(Ctemp);
		printMethod(Ctemp);
		printf("**********************\n");
		Ctemp = Ctemp->next;
    }
    
}

void printField2(struct Classtable *Ctype)
{
	struct Fieldlist *temp = Ctype->Memberfield;
	while(temp!=NULL){
		if(temp->type!=NULL)
			printFieldType(temp->type);
		else
			printClassType(temp->Ctype);
		printf("  Field name : %s  ",temp->name);
		printf("Field index : %d\n",temp->fieldIndex);
		temp = temp->next;
    }
}
void printClassType(struct Classtable *Ctype){
	printf("Field Type : %s",Ctype->name);
}
void printMethod(struct Classtable *Ctype){
	struct Memberfunclist *Mtemp = Ctype->Vfuncptr;
	while(Mtemp!=NULL){
		printf("Method name : %s  ",Mtemp->name);
		printMethodtype(Mtemp->type);
		printf("   Method Label : F%d",Mtemp->flabel);
		printf("   Method position : %d\n",Mtemp->Funcposition);
		printf("Parameters are : \n");
		struct Paramstruct *temp = Mtemp->paramlist;
		if(temp==NULL)
			printf("NULL\n");
		while(temp!=NULL)
		{
			printf("Type : %s  ",printType(temp->type) );
			printf("Name : %s\n",temp->name);
			temp=temp->next;
		}
		Mtemp = Mtemp->next;
	}
}
void printMethodtype(struct Typetable *type){
	printf("Method Type : %s",type->name);
}
void printFieldType(struct Typetable *type){
	printf("Field Type : %s \n",type->name);
}
void printField(struct Fieldlist *temp){
    while(temp!=NULL){
        printFieldType(temp->type);
        printf("Field name : %s\n", temp->name);
        printf("Field Index : %d\n",temp->fieldIndex);
        printf("Field type: %s\n",temp->type->name);
        temp=temp->next;
    }
}
char *printType(struct Typetable *type){
   // 
	return type->name;
}
void printTypetable(){
    struct Typetable * temp= Thead;
    while(temp!=NULL){
        printf("------------\n");
        printf("Type name :%s\n", temp->name);
        printf("Type size :%d\n",temp->size);
        printf("Type Fields :\n");
        printField(temp->fields);
        printf("------------\n");
        temp= temp->next;
    }
}
void print_declarations(struct Gsymbol* head){
    struct Gsymbol* curr=head;
    while(curr!=NULL){
        printf("--------------------------------\n");
        printf("name : %s,\n",curr->name);
        printf("size : %d,\n",curr->size1);
        printf("binding: %d,\n",curr->binding);
        printf("type: %s,\n",curr->type->name);
        printf("Flabel : %d\n",curr->flabel);
        printf("Declaration Type : %s\n",printvartype(curr->nodetype));
        if(curr->flabel!= -1){
            printf("parameters are:\n");
            struct Paramstruct *temp= curr->paramlist;
            while(temp!=NULL){
                printf("Type : %s  ",printType(temp->type) );
				printf("Name : %s\n",temp->name);
				temp=temp->next;
            }
        }
        printf("--------------------------------\n");
        curr=curr->next;
    }
}

void print_local_declarations(struct Lsymbol* head){
    struct Lsymbol* curr=head;
    while(curr!=NULL){
        printf("--------------------------------\n");
        printf("name : %s,\n",curr->name);
        printf("binding: %d,\n",curr->binding);
        printf("type: %s,\n",printType(curr->type));
        printField(curr->type->fields);
        printf("--------------------------------\n");
        curr=curr->next;
    }
}
char *getFunctionname(int label){
	struct Gsymbol *temp = Ghead;
	char *x="No function with this Label";
	while(temp!=NULL)
	{
		if(temp->flabel==label)
			return temp->name;
		temp=temp->next;
	}
	return x;
}
int Typesizeallocator (struct Typetable *type){
	struct Fieldlist *temp = type->fields;
	int count=0;
	while(temp!=NULL){
		count++;
		temp = temp->next;
	}
	if(count>8)
	{
		printf("Type size limit exceeded for Type %s\n",type->name);
		exit(0);
        return -1;
	}
    return count;
}
int type_guard(struct tnode* t){
   
    switch(t->nodetype){
        case _PLUS:
        case _MINUS:
        case _DIV:
        case _MUL:
            if(t->left->type != TLookup("Integer") || t->right->type!= TLookup("Integer")){
                yyerror("type mismatch : both should be integer type\n");
                exit(1);
            }
            break;

        case _EQ:
        case _GE:
        case _LE:
        case _GT:
        case _LT:
            if(t->right->type == TLookup("Type") && (t->left->type==TLookup("Integer") || t->left->type==TLookup("String"))){
                yyerror("type mismatch : both should be boolean type\n");
                exit(1);
            }
            if((t->right->type!=TLookup("Type") && ( t->left->type!=TLookup("Integer") || t->right->type!=TLookup("Integer")))){
                yyerror("type mismatch : both operands must be integer (relational) \n");
                exit(1);
            }
            break;
        
        case _IF_THEN_ELSE:
        case _IF_THEN:
        case _WHILE:
        case _DO_WHILE:
        case _REAPEAT_UNTIL:
            if(t->left->type != TLookup("Boolean")){
                yyerror("type mismatch : conditions should be boolean\n");
                exit(1);
            }
            break;
        
        case _WRITE:
            if(t->left->type == TLookup("void")|| t->left->type== TLookup("Boolean")){
                yyerror("type mismatch: write only possible with integers and strings\n");
                exit(1);
            }
            break;

        case _ASSIGN:
            //printf("type print: %s varname: %s\n",t->right->type->name, t->right->varname);
           // printf("type print: %s varname: %s\n",t->left->type->name, t->left->varname);
           
            if( t->right->type==TLookup("Type") && ( ( t->left->type==TLookup("Integer") ) || ( t->left->type==TLookup("String") ) )){
                yyerror("type mismatch: user defined type (asssignment)!\n");
                exit(1);
            }
            else if(t->right->type!=TLookup("Type") && (t->left->type != t->right->type) ){
                printf("type right: %s varname: %s\n",t->right->type->name, t->right->varname);
                printf("type left : %s varname: %s\n",t->left->type->name, t->left->varname);
                yyerror("type mismatch: both operands must be integers (assignment)\n");
                exit(1);
            }
            break;

        case _ASGN_ARRAY:
            if(t->mid->type!= TLookup("Integer")){
                yyerror("array index must be type integer!");
                exit(1);
            }
            if(t->left->type != t->right->type){
                yyerror("type mismatch:assign types not same!\n");
                exit(1);
            }
            break;
        case _READ_ARRAY:
            if(t->mid->type!= TLookup("Integer")){
                yyerror("array index must be type integer!\n");
                exit(1);
            }
            break;
    }
    return 1;
}

int check_equivalence(struct Paramstruct *Pdecl,struct Paramstruct *Pdef){
    struct Paramstruct *i,*j;
    i= Pdecl;
    j= Pdef;
    while(i!=NULL && j!=NULL){
        if( (i->type== j->type) && (strcmp(i->name,j->name) ==0 ) ){
            i= i->next;
            j= j->next;
        }
        else 
            return -1;
    }
    if(i!=NULL || j!=NULL)
	    return -1;
	else
		return 0;
}
int vartype_guard(struct tnode* t){

    return 1;
}
 
