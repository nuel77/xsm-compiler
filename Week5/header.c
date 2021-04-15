
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

void GInstall(char *name, int type, int size1, int size2, enum NodeType nodetype, struct Paramstruct *paramlist){
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
    tmp->name= name;
    tmp->type= type;
    tmp->size1= size1;
    tmp->size2= size2;
    tmp->nodetype= nodetype;
    tmp->binding= CURR_BINDING;
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
    
    CURR_BINDING += size1*size2;
    if(Ghead==NULL){
        Ghead= tmp;
    }
    else{
        tmp->next= Ghead;
        Ghead= tmp;
    }
}

void LInstall(char *name, enum VarType type, enum NodeType nodetype){
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
        while(curr->next!=NULL) 
            curr= curr->next;
        curr->next= temp;
    }
    //printf("Lhead is %s\n", Lhead->name);
}
void PInstall(char* name, int type, enum NodeType nodetype){

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
struct tnode * createTree(int val,  enum VarType type, char *varname, enum NodeType nodetype, struct tnode* left, struct tnode* mid, struct tnode* right){

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
void funcdef(int type, struct tnode *func, struct Paramstruct *Phead, struct tnode * body){

    struct Lsymbol *Ltemp;
    struct Gsymbol *Gtemp;
    struct Paramstruct *Pdef, *Pdecl;

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

    int flag;
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

void print_declarations(struct Gsymbol* head){
    struct Gsymbol* curr=head;
    while(curr!=NULL){
        printf("--------------------------------\n");
        printf("name : %s,\n",curr->name);
        printf("size : %d,\n",curr->size1);
        printf("binding: %d,\n",curr->binding);
        printf("type: %d,\n",curr->type);
        printf("Flabel : %d\n",curr->flabel);
        printf("Declaration Type : %s\n",printvartype(curr->nodetype));
        if(curr->flabel!= -1){
            printf("parameters are:\n");
            struct Paramstruct *temp= curr->paramlist;
            while(temp!=NULL){
                printf("Type : %d  ",(temp->type) );
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
        printf("type: %d,\n",curr->type);
        printf("--------------------------------\n");
        curr=curr->next;
    }
}

int codeGen(struct tnode* t){
    int l ,r, m, z, _else, _endif, reg1, reg2, location, _while_start,_while_end, l_varcount, x, y;
    struct Gsymbol* Gtemp;
    struct Lsymbol* Ltemp;
    struct Paramstruct* Ptemp;
    struct tnode* p;

    if(t== NULL) return -1;

    switch(t->nodetype){
        case _NUM:
            reg1= get_register();
            fprintf(target_file,"MOV R%d, %d\n",reg1, t->val);
            return reg1;
        case _STR:
            reg1= get_register();
            fprintf(target_file,"MOV R%d, \"%s\"\n", reg1, t->varname);
            return reg1;
        case _ID:
            reg1= get_register();
            Ltemp= LLookup(t->varname); // check if its  a local variable
            Ptemp= PLookup(t->varname); //check if its an argument of the function
            Gtemp= GLookup(t->varname); // check if its a global variable.

            /* check if inside a local variable (given first priority) */
            if(Ltemp!= NULL){
                fprintf(target_file, "MOV R%d, BP\n", reg1);
                fprintf(target_file, "ADD R%d, %d\n", reg1, Ltemp->binding); //adding relatiive binding w.r.t to BP pointer.
                fprintf(target_file, "MOV R%d, [R%d]\n",reg1, reg1);
            }
            /* if variable its a argument*/
            else if(Ptemp!= NULL){
                fprintf(target_file, "MOV R%d, BP\n", reg1);
                /* if the id is an argument, it would be added by when the function is 
                called ie, behind the base pointer. the return value and return address is 
                present behind bp hence we add 2 */
                fprintf(target_file, "SUB R%d, %d\n", reg1, Ptemp->binding + 2);
                fprintf(target_file, "MOV R%d, [R%d]\n", reg1, reg1);
            }
            //variable is a global var.
            else if(Gtemp!= NULL){
                fprintf(target_file, "MOV R%d, [%d]\n", reg1, t->Gentry->binding);
            }
            else {
                printf("unknown variable :%s line 362\n", t->varname);
                exit(1);
            }
            return reg1;

        case _ARRAY:    
            Gtemp= GLookup(t->varname);
            if(Gtemp==NULL){
                printf("Unknown variable: %s line 370\n", t->varname);
                exit(0);
            }
            m= codeGen(t->mid);
            location= Gtemp->binding;
            fprintf(target_file,"ADD R%d, %d\n",m, location);
            fprintf(target_file,"MOV R%d, [R%d]\n",m,m); 
            
            return m;

        case _MATRIX:
            Gtemp= GLookup(t->varname); 
          break;
        case _PTR:      break;
        case _ADDR:     break;

        case _FUNC:
        //function call
            Gtemp= GLookup(t->varname);
            if(Gtemp==NULL){
                printf("function not declared %s\n",t->varname);
                exit(0);
            }
            Ptemp= Gtemp->paramlist; //parameters used in the declaration
            p= t->right; //represents the paramaters used in the call

            /*check for equivalence of no of parameters*/
            x= y= 0;
            while(Ptemp!= NULL){
                x++; Ptemp= Ptemp->next;
            }
            while(p!= NULL){
                y++ ; p= p->left;
            }
            
            if(x!= y){
                printf("argument numbers do not match for declaration and definintin %s\n", t->varname);
                exit(0);
            }

            /*check for equivalence of type of parameters*/
            p= t->right;
            Ptemp= Gtemp->paramlist;
            while(Ptemp!= NULL){
                if(p->right->type != Ptemp->type){
                    printf("argument types do not match for declaration and definitin %s\n",t->varname);
                    exit(0);
                }
                p=p->left;
                Ptemp= Ptemp->next;
            }
            /*push all currrent active registers into the stack*/
            for(y=-1; y< REG_COUNT; y++){
                fprintf(target_file, "PUSH R%d\n",y+1);
            }
            REG_COUNT =-1;

            x= codeGen(t->right); // push all the arguments 

             /* calling the function */
            reg1= get_register();
            fprintf(target_file, "PUSH R%d\n",reg1); //empty register for return value
            fprintf(target_file, "CALL F%d\n",Gtemp->flabel); //call the function label
            fprintf(target_file,"POP R%d\n",reg1);  //pop out the return value
            free_register();

            /*popping out parameters after call */
            Ptemp= Gtemp->paramlist;
            reg1= get_register();
            z=0;
            while(Ptemp!= NULL){
                fprintf(target_file, "POP R%d\n", reg1);
                Ptemp= Ptemp->next; 
                z++;
            }
            free_register();

            /*Restoring registers after function call*/
            REG_COUNT= y;
            for(y; y>=0; y--){
                fprintf(target_file, "POP R%d\n",y);
                z++;
            }

            reg1= get_register();
            fprintf(target_file, "MOV R%d, SP\n", reg1);
            fprintf(target_file, "ADD R%d, %d\n",reg1, z+1); //address of the returned value
            fprintf(target_file,"MOV R%d, [R%d]\n", reg1, reg1);
            return reg1;
            break;
        
        case _ARG:
            if(t!= NULL){
                r= codeGen(t->right);
                free_register();
                fprintf(target_file, "PUSH R%d \n",r);
                l= codeGen(t->left);
                free_register();
            }
            return -1;
        
        case _RET:
            l_varcount=0;
            for(Ltemp= Lhead; Ltemp!= NULL; Ltemp=Ltemp->next)
                l_varcount++;
            
            l= codeGen(t->left); //return value;
            reg1= get_register();
            fprintf(target_file, "MOV R%d, BP\n",reg1 );
			fprintf(target_file, "SUB R%d, 2\n",reg1 ); //address of return space
			fprintf(target_file, "MOV [R%d], R%d\n",reg1, l ); //Put return value in return space
			free_register();
			free_register();
			fprintf(target_file,"SUB SP, %d\n",l_varcount);	// Pop Local Variables
			fprintf(target_file,"MOV BP,[SP]\n"); //make the base pointer point to caller base
			fprintf(target_file,"POP R0\n");
			fprintf(target_file,"RET\n");
			break;

        case _ASSIGN:
			r = codeGen(t->right); //value to be stored
            reg1= get_register();
            if(Lhead == NULL){
                printf("local variables not declared\n");
            }
			Ltemp=LLookup(t->left->varname);
			Ptemp=PLookup(t->left->varname);
			Gtemp=GLookup(t->left->varname);
			if(Ltemp==NULL  && Ptemp==NULL && Gtemp==NULL)
			{
				printf("Unknown variable: %s line 496\n", t->left->varname);
                exit(0);
            }
            if(Ltemp!= NULL){
                fprintf(target_file, "MOV R%d, BP\n", reg1);
				fprintf(target_file, "ADD R%d, %d\n", reg1, Ltemp->binding);
				fprintf(target_file, "MOV [R%d], R%d\n", reg1, r);
            }
            else if(Ptemp!=NULL){
                fprintf(target_file, "MOV R%d, BP\n", reg1);
				fprintf(target_file, "SUB R%d, %d\n", reg1, Ptemp->binding+2);
				fprintf(target_file, "MOV [R%d], R%d\n", reg1, r);
            }
            else if(Gtemp!= NULL){
				fprintf(target_file, "MOV [%d], R%d\n", Gtemp->binding, r);
            }
            free_register();
			free_register();
			return -1;
        
        case _ASGN_ARRAY:
            r= codeGen(t->right);
            m= codeGen(t->mid);
            Gtemp=GLookup(t->left->varname);
            if(Gtemp==NULL){
                printf("Unknown variable: %s line 521\n", t->varname);
                exit(0);
            }
            location= Gtemp->binding;
            fprintf(target_file, "ADD R%d, %d\n",m, location);
            fprintf(target_file,"MOV [R%d], R%d\n",m, r);
            free_register();
            free_register();
            return -1;
        case _ASGN_MATRIX:  break;
        case _ASGN_PTR:     break;
        case _ASGN_PTR_ADDR:break;
            
        case _PLUS:
            l= codeGen(t->left);
            r= codeGen(t->right);
            fprintf(target_file,"ADD R%d,R%d\n",l, r);
            free_register();
            return l;
        case _MINUS:
            l= codeGen(t->left);
            r= codeGen(t->right);
            fprintf(target_file,"SUB R%d,R%d\n",l, r);
            free_register();
            return l;
        case _DIV:
            l= codeGen(t->left);
            r= codeGen(t->right);
            fprintf(target_file,"DIV R%d,R%d\n",l, r);
            free_register();
            return l;
        case _MUL:
            l= codeGen(t->left);
            r= codeGen(t->right);
            fprintf(target_file,"MUL R%d,R%d\n",l, r);
            free_register();
            return l;
        case _LT:
            l= codeGen(t->left);
            r= codeGen(t->right);
            fprintf(target_file,"LT R%d,R%d\n",l, r);
            free_register();
            return l;
        case _GT:
            l= codeGen(t->left);
            r= codeGen(t->right);
            fprintf(target_file,"GT R%d,R%d\n",l, r);
            free_register();
            return l;
        case _LE:
            l= codeGen(t->left);
            r= codeGen(t->right);
            fprintf(target_file,"LE R%d,R%d\n",l, r);
            free_register();
            return l;
        case _GE:
            l= codeGen(t->left);
            r= codeGen(t->right);
            fprintf(target_file,"GE R%d,R%d\n",l, r);
            free_register();
            return l;
        case _EQ:
            l= codeGen(t->left);
            r= codeGen(t->right);
            fprintf(target_file,"EQ R%d,R%d\n",l, r);
            free_register();
            return l;
        case _NE:
            l= codeGen(t->left);
            r= codeGen(t->right);
            fprintf(target_file,"NE R%d,R%d\n",l, r);
            free_register();
            return l;
        
        case _CONNECTOR:
            l= codeGen(t->left);
            r= codeGen(t->right);
            return -1;

        case _READ:
			reg1 = get_register();
            Ltemp=LLookup(t->left->varname);
			Ptemp=PLookup(t->left->varname);
			Gtemp=GLookup(t->left->varname);

            if( (Ltemp==NULL) && (Ptemp==NULL) && (Gtemp==NULL) )
			{
				printf("Unknown variable: %s line 608\n", t->left->varname);
				exit(1);
			}

			if(Ltemp!=NULL)
			{
				fprintf(target_file, "MOV R%d, BP\n", reg1);
				fprintf(target_file, "ADD R%d, %d\n", reg1, Ltemp->binding);
			}
			else if(Ptemp!=NULL)
			{
				fprintf(target_file, "MOV R%d, BP\n", reg1);
				fprintf(target_file, "SUB R%d, %d\n", reg1, Ptemp->binding+2);
			}
			else if(Gtemp!=NULL)
					fprintf(target_file, "MOV R%d, %d\n",reg1, Gtemp->binding);
         
			reg2 = get_register();
			fprintf(target_file,"MOV R%d, \"Read\"\n",reg2);
			fprintf(target_file,"PUSH R%d\n",reg2);
			fprintf(target_file,"MOV R%d, -1\n",reg2);
			fprintf(target_file,"PUSH R%d\n",reg2);
			fprintf(target_file,"MOV R%d, R%d\n",reg2,reg1);
			fprintf(target_file,"PUSH R%d\n",reg2);
			fprintf(target_file,"PUSH R%d\n",reg2);
			fprintf(target_file,"PUSH R%d\n",reg2);
			fprintf(target_file,"CALL 0\n");
			fprintf(target_file,"POP R%d\n",reg2);
			fprintf(target_file,"POP R%d\n",reg2);
			fprintf(target_file,"POP R%d\n",reg2);
			fprintf(target_file,"POP R%d\n",reg2);
			fprintf(target_file,"POP R%d\n",reg2);
            free_register();
            free_register();
			return -1;
        
        case _READ_ARRAY:  
            Gtemp= GLookup(t->left->varname);
            if(Gtemp==NULL){
                printf("undefined variable %s", t->left->varname);
                exit(1);
            }
            reg1= get_register();
            m= codeGen(t->mid);
            location= Gtemp->binding;
            fprintf(target_file,"ADD R%d, %d\n", m, location );
            fprintf(target_file,"MOV R%d, \"Read\"\n", reg1);
            fprintf(target_file,"PUSH R%d\n",reg1);
			fprintf(target_file,"MOV R%d, -1\n",reg1);
			fprintf(target_file,"PUSH R%d\n",reg1);
			fprintf(target_file,"MOV R%d, R%d\n",reg1,m);
			fprintf(target_file,"PUSH R%d\n",reg1);
			fprintf(target_file,"PUSH R%d\n",reg1);
			fprintf(target_file,"PUSH R%d\n",reg1);
			fprintf(target_file,"CALL 0\n");
			fprintf(target_file,"POP R%d\n",reg1);
			fprintf(target_file,"POP R%d\n",reg1);
			fprintf(target_file,"POP R%d\n",reg1);
			fprintf(target_file,"POP R%d\n",reg1);
			fprintf(target_file,"POP R%d\n",reg1);
            free_register();
            free_register();
            return -1;
        case _READ_MATRIX:  break;
        case _READ_PTR :    break;

		case _WRITE:
			l = codeGen(t->left);
			reg1 = get_register();
			fprintf(target_file,"MOV R%d, \"Write\"\n",reg1);
			fprintf(target_file,"PUSH R%d\n",reg1);
			fprintf(target_file,"MOV R%d, -2\n",reg1);
			fprintf(target_file,"PUSH R%d\n",reg1);
			fprintf(target_file,"PUSH R%d\n",l);
			fprintf(target_file,"PUSH R%d\n",reg1);
			fprintf(target_file,"PUSH R%d\n",reg1);
			fprintf(target_file,"CALL 0\n");
			fprintf(target_file,"POP R%d\n",reg1);
			fprintf(target_file,"POP R%d\n",reg1);
			fprintf(target_file,"POP R%d\n",reg1);
			fprintf(target_file,"POP R%d\n",reg1);
			fprintf(target_file,"POP R%d\n",reg1);
			free_register();
			free_register();
			return -1;
        
        case _IF_THEN_ELSE:
            _else= next_label();
            _endif= next_label();
            l= codeGen(t->left);
            fprintf(target_file,"JZ R%d, L%d\n", l, _else);
            free_register();
            m= codeGen(t->mid);
            fprintf(target_file, "JMP L%d\n",_endif);
            fprintf(target_file,"L%d:\n",_else);
            r= codeGen(t->right);
            fprintf(target_file,"L%d:\n",_endif);
            return -1;
        
        case _IF_THEN:
            _endif= next_label();
            l= codeGen(t->left);
            fprintf(target_file,"JZ R%d, L%d\n",l, _endif);
            free_register();
            m= codeGen(t->mid);
            fprintf(target_file,"L%d:\n", _endif);
            return -1;
        
        case _WHILE:
            _while_start= next_label();
            _while_end= next_label();
            push_to_LL(_while_start, _while_end); //for break and continue statements
            fprintf(target_file, "L%d:\n", _while_start);
            l= codeGen(t->left);
            fprintf(target_file,"JZ R%d, L%d\n",l, _while_end);
            free_register();
            m= codeGen(t->mid);
            fprintf(target_file,"JMP L%d\n",_while_start);
            fprintf(target_file,"L%d:\n", _while_end);
            pop_from_LL();
            return -1;
        
        case _DO_WHILE:
            _while_start= next_label();
            _while_end= next_label();
            push_to_LL(_while_start, _while_end);
            fprintf(target_file, "L%d\n", _while_start);
            m= codeGen(t->mid);
            l= codeGen(t->left);
            fprintf(target_file, "JNZ R%d, L%d\n", l, _while_start);
            free_register();
            fprintf(target_file,"L%d:\n", _while_end);
            pop_from_LL();
            return -1;
        
        case _REAPEAT_UNTIL:
            _while_start= next_label();
            _while_end= next_label();
            push_to_LL(_while_start, _while_end);
            fprintf(target_file, "L%d:\n", _while_start);
            m= codeGen(t->mid);
            l= codeGen(t->left);
            fprintf(target_file, "JZ R%d, L%d\n",l, _while_start);
            free_register();
            fprintf(target_file,"L%d:\n", _while_end);
            pop_from_LL();
            return -1;
        
        case _BREAK:
            if(loop_head!=NULL)
                fprintf(target_file,"JMP L%d\n",loop_head->brk);
            return -1;
        case _CONTINUE:
            if(loop_head!=NULL)
                fprintf(target_file, "JMP L%d\n",loop_head->cnt);
            return -1;
    }
}

void initialxsmcode(){
	fprintf(target_file,"0\n2056\n0\n0\n0\n0\n0\n0\n");
	fprintf(target_file,"MOV SP, %d\n",CURR_BINDING-1);
	fprintf(target_file,"MOV BP, %d\n",CURR_BINDING);
	fprintf(target_file,"PUSH R0\n");
	fprintf(target_file,"CALL MAIN\n");
	fprintf(target_file,"INT 10\n");
}

void end_program(){
		fprintf(target_file,"INT 10");
}
int type_guard(struct tnode* t){
   
    switch(t->nodetype){
        case _PLUS:
        case _MINUS:
        case _DIV:
        case _MUL:
            if(t->left->type != _inttype || t->right->type!= _inttype){
                yyerror("type mismatch : both should be integer type\n");
                exit(1);
            }
            break;

        case _EQ:
        case _GE:
        case _LE:
        case _GT:
        case _LT:
            if(t->left->type != _inttype || t->right->type!= _inttype){
                yyerror("type mismatch : both should be boolean type\n");
                exit(1);
            }
            break;
        
        case _IF_THEN_ELSE:
        case _IF_THEN:
        case _WHILE:
        case _DO_WHILE:
        case _REAPEAT_UNTIL:
            if(t->left->type != _booltype){
                yyerror("type mismatch : conditions should be boolean\n");
                exit(1);
            }
            break;
        
        case _WRITE:
            if(t->left->type == _typeless|| t->left->type== _booltype){
                yyerror("type mismatch: write only possible with integers and strings\n");
                exit(1);
            }
            break;
        case _ASSIGN:
            
            if(t->left->type!=t->right->type){
                yyerror("type mismatch: assign types not same!\n");
                exit(1);
            }
            break;
        case _ASGN_ARRAY:
            if(t->mid->type!= _inttype){
                yyerror("array index must be type integer!");
                exit(1);
            }
            if(t->left->type != t->right->type){
                yyerror("type mismatch:assign types not same!\n");
                exit(1);
            }
            break;
        case _READ_ARRAY:
            if(t->mid->type!= _inttype){
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
    if(i==NULL && j==NULL) return 1;
    else return -1;
}
int vartype_guard(struct tnode* t){

    return 1;
}
 
