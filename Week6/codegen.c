#include "header.c"
int codeGen(struct tnode* t){
    int l ,r, m, z, _else, _endif, reg1, reg2, location, _while_start,_while_end, l_varcount, x, y;
    struct tnode *p;
	struct Lsymbol *Ltemp;
	struct Paramstruct *Ptemp;
	struct Gsymbol *Gtemp;
	struct Typetable *Ttemp;
	struct Fieldlist *Ftemp;

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
            if((Ltemp!=NULL) && (Ptemp!=NULL)){
				printf("Multiple Declaration Local variable and Formal Argument\n");
				exit(0);
			}

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

        case _FIELD:
            reg1= get_register();
            Ltemp=LLookup(t->left->varname);
			Ptemp=PLookup(t->left->varname);
			Gtemp=GLookup(t->left->varname);
            if((Ltemp!=NULL) && (Ptemp!=NULL)){
				printf("Multiple Declaration Local variable and Formal Argument\n");
				exit(0);
			}
            if(Ltemp!=NULL){
				Ttemp=Ltemp->type;
				fprintf(target_file,"MOV R%d, BP\n",reg1);
				fprintf(target_file, "ADD R%d, %d\n", reg1, Ltemp->binding);
				fprintf(target_file,"MOV R%d, [R%d]\n",reg1,reg1);
			}
            else if(Ptemp!=NULL){
				Ttemp=Ptemp->type;
				fprintf(target_file, "MOV R%d, BP\n", reg1);
				fprintf(target_file, "SUB R%d, %d\n", reg1, Ptemp->binding+2);
				fprintf(target_file,"MOV R%d, [R%d]\n",reg1,reg1);
			}
			else if(Gtemp!=NULL){
				Ttemp=Gtemp->type;
				fprintf(target_file,"MOV R%d, [%d]\n",reg1,Gtemp->binding);
			}
            else{
				printf("Variable Not Declared : %s\n", t->left->varname);
				exit(1);
			}

			p=t;

			while(p->right!=NULL){
				Ftemp=FLookup(Ttemp,p->right->left->varname);
				if(Ftemp==NULL){
					printf("Unknown identifier in FIELD: %s\n", p->right->left->varname);
					exit(1);
				}
				fprintf(target_file, "ADD R%d, %d\n",reg1,Ftemp->fieldIndex);
				fprintf(target_file, "MOV R%d, [R%d]\n",reg1,reg1);
				Ttemp=Ftemp->type;
				p=p->right;
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

        case _INIT :
			x = getReg();
			fprintf(target_file, "MOV R%d, \"Heapset\"\n", x);
			fprintf(target_file, "PUSH R%d\n", x);
			fprintf(target_file, "PUSH R%d\n", x);
			fprintf(target_file, "PUSH R%d\n", x);
			fprintf(target_file, "PUSH R%d\n", x);
			fprintf(target_file, "PUSH R%d\n", x);
			fprintf(target_file, "CALL 0\n");
			fprintf(target_file, "POP R%d\n", x);
			fprintf(target_file, "POP R%d\n", x);
			fprintf(target_file, "POP R%d\n", x);
			fprintf(target_file, "POP R%d\n", x);
			fprintf(target_file, "POP R%d\n", x);
			fprintf(target_file, "MOV R%d, 0\n", x);
			return x;
			break;

		case _ALLOC :
			x = getReg();
			y = getReg();
			fprintf(target_file, "MOV R%d, \"Alloc\"\n", y);
			fprintf(target_file, "PUSH R%d\n", y);
			fprintf(target_file, "PUSH R%d\n", y);
			fprintf(target_file, "PUSH R%d\n", y);
			fprintf(target_file, "PUSH R%d\n", y);
			fprintf(target_file, "PUSH R%d\n", y);
			fprintf(target_file, "CALL 0\n");
			fprintf(target_file, "POP R%d\n", x);
			fprintf(target_file, "POP R%d\n", y);
			fprintf(target_file, "POP R%d\n", y);
			fprintf(target_file, "POP R%d\n", y);
			fprintf(target_file, "POP R%d\n", y);
			freeReg();
			return x;
			break;

		case _FREE :
			x = codeGen(t->left);
			y = getReg();
			fprintf(target_file, "MOV R%d, \"Free\"\n", y);
			fprintf(target_file, "PUSH R%d\n", y);
			fprintf(target_file, "PUSH R%d\n", x);
			fprintf(target_file, "PUSH R%d\n", y);
			fprintf(target_file, "PUSH R%d\n", y);
			fprintf(target_file, "PUSH R%d\n", y);
			fprintf(target_file, "CALL 0\n");
			fprintf(target_file, "POP R%d\n", y);
			fprintf(target_file, "POP R%d\n", y);
			fprintf(target_file, "POP R%d\n", y);
			fprintf(target_file, "POP R%d\n", y);
			fprintf(target_file, "POP R%d\n", y);
			freeReg();
			freeReg();
			return -1;
			break;

		case _NULL:
			x = getReg();
			fprintf(target_file, "MOV R%d, -1\n", x);
			return x;

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
        case _ASSIGN_FIELD:
			x = codeGen(t->right);
			y = getReg();

			Ltemp=LLookup(t->left->left->varname);
			Ptemp=PLookup(t->left->left->varname);
			Gtemp=GLookup(t->left->left->varname);

			if( (Ltemp==NULL) && (Ptemp==NULL) && (Gtemp==NULL) )
			{
				printf("Unknown variable: %s\n", t->left->varname);
				exit(1);
			}

			if(Ltemp!=NULL)
			{
				Ttemp=Ltemp->type;
				fprintf(target_file, "MOV R%d, BP\n", y);
				fprintf(target_file, "ADD R%d, %d\n", y, Ltemp->binding);
				fprintf(target_file, "MOV R%d, [R%d]\n", y,y);
			}
			else if(Ptemp!=NULL)
			{
				Ttemp=Ptemp->type;
				fprintf(target_file, "MOV R%d, BP\n", y);
				fprintf(target_file, "SUB R%d, %d\n", y, Ptemp->binding+2);
				fprintf(target_file, "MOV R%d, [R%d]\n", y,y);
			}
			else if(Gtemp!=NULL)
			{
					Ttemp=Gtemp->type;
					fprintf(target_file, "MOV R%d, [%d]\n", y,Gtemp->binding);
			}

			p=t->left;

			while(p->right->right!=NULL)
			{
				Ftemp=FLookup(Ttemp,p->right->left->varname);
				if(Ftemp==NULL)
				{
					printf("Unknown identifier in FIELD: %s\n", p->right->left->varname);
					exit(1);
				}
				fprintf(target_file, "ADD R%d, %d\n",y,Ftemp->fieldIndex);
				fprintf(target_file, "MOV R%d, [R%d]\n", y,y);

				Ttemp=Ftemp->type;
				p=p->right;
			}

			Ftemp=FLookup(Ttemp,p->right->left->varname);
			if(Ftemp==NULL)
			{
				printf("Unknown identifier in FIELD: %s\n", p->right->left->varname);
				exit(1);
			}
			fprintf(target_file, "ADD R%d, %d\n",y,Ftemp->fieldIndex);
			fprintf(target_file, "MOV [R%d], R%d\n", y,x);

			freeReg();
			freeReg();
			return -1;
            
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
        case _READ_FIELD:
			Ltemp=LLookup(t->left->left->varname);
			Ptemp=PLookup(t->left->left->varname);
			Gtemp=GLookup(t->left->left->varname);

			x=getReg();

			if( (Ltemp==NULL) && (Ptemp==NULL) && (Gtemp==NULL) ){
				printf("Unknown variable: %s\n", t->left->varname);
				exit(1);
			}

			if(Ltemp!=NULL){
				Ttemp=Ltemp->type;
				fprintf(target_file, "MOV R%d, BP\n", x);
				fprintf(target_file, "ADD R%d, %d\n", x, Ltemp->binding);
				fprintf(target_file, "MOV R%d, [R%d]\n", x,x);
			}
			else if(Ptemp!=NULL){
				Ttemp=Ptemp->type;
				fprintf(target_file, "MOV R%d, BP\n", x);
				fprintf(target_file, "SUB R%d, %d\n", x, Ptemp->binding+2);
				fprintf(target_file, "MOV R%d, [R%d]\n", x,x);
			}
			else if(Gtemp!=NULL){
				Ttemp=Gtemp->type;
				fprintf(target_file, "MOV R%d, [%d]\n",x, Gtemp->binding);
			}

			p=t->left;

			while(p->right->right!=NULL){
				Ftemp=FLookup(Ttemp,p->right->left->varname);
				if(Ftemp==NULL){
					printf("Unknown identifier in FIELD: %s\n", p->right->left->varname);
					exit(1);
				}
				fprintf(target_file, "ADD R%d, %d\n",x,Ftemp->fieldIndex);
				fprintf(target_file, "MOV R%d, [R%d]\n", x,x);

				Ttemp=Ftemp->type;
				p=p->right;
			}

			Ftemp=FLookup(Ttemp,p->right->left->varname);

			if(Ftemp==NULL){
				printf("Unknown identifier in FIELD: %s\n", p->right->left->varname);
				exit(1);
			}
			fprintf(target_file, "ADD R%d, %d\n",x,Ftemp->fieldIndex);

			y = getReg();
			fprintf(target_file,"MOV R%d, \"Read\"\n",y);
			fprintf(target_file,"PUSH R%d\n",y);
			fprintf(target_file,"MOV R%d, -1\n",y);
			fprintf(target_file,"PUSH R%d\n",y);
			fprintf(target_file,"MOV R%d, R%d\n",y,x);
			fprintf(target_file,"PUSH R%d\n",y);
			fprintf(target_file,"PUSH R%d\n",y);
			fprintf(target_file,"PUSH R%d\n",y);
			fprintf(target_file,"CALL 0\n");
			fprintf(target_file,"POP R%d\n",y);
			fprintf(target_file,"POP R%d\n",y);
			fprintf(target_file,"POP R%d\n",y);
			fprintf(target_file,"POP R%d\n",y);
			fprintf(target_file,"POP R%d\n",y);
			freeReg();
			freeReg();
			return -1;
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