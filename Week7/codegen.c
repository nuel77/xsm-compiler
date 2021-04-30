#include "header.c"
int codeGen(struct tnode* t){
    int l ,r, m, _else, _endif, reg1, reg2, location, _while_start,_while_end, l_varcount, x, y,a,b,c,z;
    struct tnode *p;
	struct Lsymbol *Ltemp;
	struct Paramstruct *Ptemp;
	struct Gsymbol *Gtemp;
	struct Typetable *Ttemp;
	struct Fieldlist *Ftemp;
    struct Memberfunclist *Mtemp;
	struct Classtable *Ctemp;

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
                printf("unknown variable _ID :%s line 362\n", t->varname);
                exit(1);
            }
            return reg1;

        case _FIELD:
            reg1= get_register();
            //check if its a has self type.
            if(strcmp(t->varname,"\0")!=0){
                z=3;
                Ptemp=Phead;
                while(Ptemp!=NULL){
                    z++;
                    Ptemp=Ptemp->next;
                }
                fprintf(target_file, "MOV R%d, BP\n", reg1);
				fprintf(target_file, "SUB R%d, %d\n", reg1, z+1);
				fprintf(target_file, "MOV R%d, [R%d]\n", reg1, reg1);

                //get self class.
                Ctemp=Clookup(t->varname);
                Ftemp=Ctemp->Memberfield;
                z=0;
                while(strcmp(Ftemp->name, t->left->varname)){
                    z++;
                    if(Ftemp->type==NULL){
                        z++;
                    }
                    Ftemp= Ftemp->next;
                }
                fprintf(target_file, "ADD R%d, %d\n", reg1, z);
				fprintf(target_file, "MOV R%d, [R%d]\n", reg1, reg1);

                Ttemp= Ftemp->type;
                p=t->right;
                while(p!=NULL){
                    Ftemp= FLookup(Ttemp,p->left->varname);
                    if(Ftemp==NULL){
                        printf("unkown identifier in field: %s\n",p->left->varname);
                        exit(0);
                    }
                    fprintf(target_file, "ADD R%d, %d\n", x, Ftemp->fieldIndex);
					fprintf(target_file, "MOV R%d, [R%d]\n", x, x);
					Ttemp=Ftemp->type;
					p=p->right;
                }
            }
            else{
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
            }
			return reg1;

        case _ARRAY:    
            Gtemp= GLookup(t->varname);
            if(Gtemp==NULL){
                printf("Unknown variable _ARRAY: %s line 370\n", t->varname);
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
            x=0; y--;
            p= t->right;
            Ptemp= Gtemp->paramlist;
            while(Ptemp!= NULL){
                z=0;
                p=t->right;
                while(z<y){
                    z++;
                    p=p->left;
                }
                if(p->right->type != Ptemp->type){
                    printf("Incorrect Parameter (%s) type for function %s\n",Ptemp->name,t->varname);
                    exit(0);
                }
                y--;
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

        case _METHOD1:
            Gtemp= GLookup(t->left->varname);
            if(Gtemp==NULL){
                printf("object %s is not declared\n",t->left->varname);
                exit(0);
            }
            Ctemp= Gtemp->Ctype;
            Mtemp= Ctemp->Vfuncptr;
            //find the specified method in class definition
            while(Mtemp!=NULL){
                if(strcmp(Mtemp->name,t->mid->varname)==0)
                    break;
                Mtemp=Mtemp->next;
            }
            Ptemp= Mtemp->paramlist; //parameter in class definintion
            p=t->right; //given parameters.

            x=y=0;
            while(Ptemp!=NULL){
                x++;
                Ptemp=Ptemp->next;
            }
            while(p!=NULL){
                y++;
                p=p->left;
            }
            //check if no of parmerters are equal
            if(x!=y){
                printf("Incorrect No of Arguments for Function %s\n",t->varname);
				exit(0);
            }
            /*just checking the param types for decl and def here, 
            paramlist in Gtemp are inserted in reverse order to paramlist in fucntion call*/
            x=0;
            y--;
            Ptemp= Gtemp->paramlist;
            while(Ptemp!=NULL){
                z=0;
                p= t->right;
                while(z<y){
                    z++;
                    p=p->left;
                }
                if(Ptemp->type != p->right->type){
                    printf("Incorrect Parameter (%s) type for function %s\n",Ptemp->name,t->mid->varname);
					exit(0);
                }
                y--;
                Ptemp=Ptemp->next;
            }
            //push all currrent active registers to stack
            for(y=-1;y<REG_COUNT;y++)													
				fprintf(target_file, "PUSH R%d\n",y+1);

            REG_COUNT =-1;
            //push the binding 
            x=get_register();
			fprintf(target_file,"MOV R%d, [%d]\n",x,Gtemp->binding);
			fprintf(target_file,"PUSH R%d\n",x);
			fprintf(target_file,"MOV R%d, [%d]\n",x,Gtemp->binding+1);
			fprintf(target_file,"PUSH R%d\n",x);
			free_register();
            //push the arguments
			x=codeGen(t->right);												
			x=get_register();
            //push return value register
			fprintf(target_file, "PUSH R%d\n", x);			
			fprintf(target_file, "MOV R%d, [%d]\n", x, Gtemp->binding+1);
			fprintf(target_file, "ADD R%d, %d\n", x, Mtemp->Funcposition);
			fprintf(target_file, "MOV R%d, [R%d]\n", x, x);
			fprintf(target_file, "CALL R%d\n", x);
            //pop return value
			fprintf(target_file,"POP R%d\n",x);				

			free_register();

			z=0;
			Ptemp=Mtemp->paramlist;
			x=get_register();
            //pop arguments
			while(Ptemp!=NULL){
				fprintf(target_file,"POP R%d\n",x);		
				Ptemp=Ptemp->next;
				z++;
			}

			free_register();
            // Pop self address
			fprintf(target_file, "SUB SP, 2\n");			
			z+=2;
			REG_COUNT=y;
            //Pop Registers
			for(;y>=0;y--){
				fprintf(target_file, "POP R%d\n", y);			//Pop Registers
				z++;
			}
			x=get_register();
			fprintf(target_file, "MOV R%d, SP\n",x);
			fprintf(target_file,"ADD R%d, %d\n",x,z+1);
			fprintf(target_file,"MOV R%d, [R%d]\n",x,x);

			return x;
        
        case _METHOD2: //self.func()
            Ctemp= Clookup(t->varname);
            Mtemp= Ctemp->Vfuncptr;
            b=0;
            //find the given func from class def
            while(Mtemp!=NULL){
                if(strcmp(Mtemp->name,t->left->varname)==0)
                    break;
                Mtemp= Mtemp->next;
                b++;
            }
            Ptemp= Mtemp->paramlist;
            p= t->right;
            x=y=0;
            while(Ptemp!=NULL){
                x++;
                Ptemp=Ptemp->next;
            }
            while(p!=NULL){
                y++;
                p=p->left;
            }
            //checks for parameter # and types like before
            if(x!=y){
                printf("Incorrect No of Arguments for Function %s\n",t->varname);
				exit(0);
            }
            Ptemp= Phead;
            c=0;
            while(Ptemp!=NULL){
                c++; Ptemp=Ptemp->next;
            }
            x=0;
            y--;
            Ptemp= Mtemp->paramlist;
            while(Ptemp!=NULL){
                z=0;
                p=t->right;
                while(z<y){
                    z++; p=p->left;
                }
                if(Ptemp->type!= p->right->type){
                    printf("Incorrect Parameter (%s) type for function %s\n",Ptemp->name,t->mid->varname);
					exit(0);
                }
                y--;
                Ptemp=Ptemp->next;
            }
            //push the currrent registers to stack
            for(y=-1;y<REG_COUNT;y++)													//Push Existing Registers
				fprintf(target_file, "PUSH R%d\n",y+1);
            REG_COUNT=-1;

            x=get_register();
			z=get_register();
			fprintf(target_file,"MOV R%d, BP\n",x);
			fprintf(target_file,"SUB R%d, %d\n",x,c+4);
			fprintf(target_file,"MOV R%d, [R%d]\n",z,x);
			fprintf(target_file,"PUSH R%d\n",z);
			fprintf(target_file,"ADD R%d, 1\n",x);
			fprintf(target_file,"MOV R%d, [R%d]\n",z,x);
			fprintf(target_file,"PUSH R%d\n",z);
			free_register();
			free_register();

            //Push Arguments
			x=codeGen(t->right);												
			
            //Push return value
            x=get_register();
			fprintf(target_file, "PUSH R%d\n", x);	

            //find label from virtual function table pointer
			fprintf(target_file,"MOV R%d, BP\n",x);			
			fprintf(target_file,"SUB R%d, %d\n",x,c+3);
			fprintf(target_file,"MOV R%d, [R%d]\n",x,x);
			fprintf(target_file,"ADD R%d, %d\n",x,b);
			fprintf(target_file,"MOV R%d, [R%d]\n",x,x);
			fprintf(target_file, "CALL R%d\n", x);

            //Pop return value
			fprintf(target_file,"POP R%d\n",x);					
			free_register();

			z=0;
			Ptemp=Mtemp->paramlist;
			x=get_register();

            //Pop Arguments
			while(Ptemp!=NULL){
				fprintf(target_file,"POP R%d\n",x);			
				Ptemp=Ptemp->next;
				z++;
			}

			free_register();
            // Pop self address
			fprintf(target_file, "SUB SP, 2\n");			
			z+=2;

			REG_COUNT=y;
            //Pop Registers
			for(;y>=0;y--){
				fprintf(target_file, "POP R%d\n", y);			
				z++;
			}
			x=get_register();
			fprintf(target_file, "MOV R%d, SP\n",x);
			fprintf(target_file,"ADD R%d, %d\n",x,z+1);
			fprintf(target_file,"MOV R%d, [R%d]\n",x,x);

			return x;

        case _METHOD3: //something.something.somefunc()
            Ctemp = Class;
            Ftemp= Ctemp->Memberfield;
            a=0;
            while(strcmp(Ftemp->name,t->left->left->varname)){
                Ftemp= Ftemp->next;
                a++;
            }
            Ctemp=Ftemp->Ctype;
            b=0;
            while(Mtail!=NULL){
                if(strcmp(Mtemp->name,t->mid->varname)==0)
                    break;
                Mtemp=Mtemp->next;
                b++;
            }
            Ptemp= Mtemp->paramlist;
            p=t->right;
            x=y=0;
            while(Ptemp!=NULL){
                x++; Ptemp=Ptemp->next;
            }
            while(p!=NULL){
                y++; p=p->left;
            }
            //check for # and type of parameters in decl and def
            if(x!=y){
                printf("Incorrect No of Arguments for Function %s\n",t->varname);
				exit(0);
            }
            Ptemp=Phead;
            c=0;
            while(Ptemp!=NULL){
                c++;
                Ptemp=Ptemp->next;
            }
            x=0;
            y--;
            Ptemp=Mtemp->paramlist;
            while(Ptemp!=NULL){
				z=0;
				p=t->right;
				while(z<y){
					z++;
					p=p->left;
				}
				if(Ptemp->type!=p->right->type){
					printf("Incorrect Parameter (%s) type for function %s\n",Ptemp->name,t->mid->varname);
					exit(0);
				}
				y--;
				Ptemp=Ptemp->next;
			}

			for(y=-1;y<REG_COUNT;y++)													//Push Existing Registers
				fprintf(target_file, "PUSH R%d\n",y+1);

			REG_COUNT=-1;

			x=get_register();
			y=get_register();

			fprintf(target_file,"MOV R%d, BP\n",x);
			fprintf(target_file,"SUB R%d, %d\n",x,c+4);
			fprintf(target_file,"MOV R%d, [R%d]\n",x,x);
			fprintf(target_file,"ADD R%d, %d\n",x,a);
			fprintf(target_file,"MOV R%d, [R%d]\n",y,x);
			fprintf(target_file,"PUSH R%d\n",y);
			fprintf(target_file,"ADD R%d, 1\n",x);
			fprintf(target_file,"MOV R%d, [R%d]\n",y,x);
			fprintf(target_file,"PUSH R%d\n",y);

			free_register();
			free_register();

			x=codeGen(t->right);												//Push Arguments
			x=get_register();

			fprintf(target_file, "PUSH R%d\n", x);			//Push return value

			fprintf(target_file,"MOV R%d, BP\n",x);			//To find label from virtual function table pointer
			fprintf(target_file,"SUB R%d, %d\n",x,c+4);
			fprintf(target_file,"MOV R%d, [R%d]\n",x,x);
			fprintf(target_file,"ADD R%d, %d\n",x,a+1);
			fprintf(target_file,"MOV R%d, [R%d]\n",x,x);
			fprintf(target_file,"ADD R%d, %d\n",x,b);
			fprintf(target_file,"MOV R%d, [R%d]\n",x,x);
			fprintf(target_file, "CALL R%d\n", x);

			fprintf(target_file,"POP R%d\n",x);					//Pop return value

			free_register();

			z=0;
			Ptemp=Mtemp->paramlist;
			x=get_register();

			while(Ptemp!=NULL){
				fprintf(target_file,"POP R%d\n",x);			//Pop Arguments
				Ptemp=Ptemp->next;
				z++;
			}

			fprintf(target_file, "SUB SP, 2\n");			// Pop self address
			z+=2;

			free_register();
			REG_COUNT=y;
			for(y--;y>=0;y--){
				fprintf(target_file, "POP R%d\n", y);			//Pop Registers
				z++;
			}

			x=get_register();
			fprintf(target_file, "MOV R%d, SP\n",x);
			fprintf(target_file,"ADD R%d, %d\n",x,z+1);
			fprintf(target_file,"MOV R%d, [R%d]\n",x,x);
			return x;


        case _INIT :
			x = get_register();
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
			x = get_register();
			y = get_register();
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
			free_register();
			return x;
			break;

		case _FREE :
			x = codeGen(t->left);
			y = get_register();
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
			free_register();
			free_register();
			return -1;
			break;

		case _NULL:
			x = get_register();
			fprintf(target_file, "MOV R%d, -1\n", x);
			return x;

        case _BRKP:
			fprintf(target_file,"BRKP\n");
			return -1;

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
				printf("Unknown variable _ASSIGN: %s line 496\n", t->left->varname);
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
                printf("Unknown variable _ASGN_ARRAY: %s line 521\n", t->varname);
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
			y = get_register();
            if(strcmp(t->left->varname,"\0")!=0){
                Ctemp= Clookup(t->left->varname);
                z=3;
                Ptemp=Phead;
                while(Ptemp!=NULL){
                    z++;
                    Ptemp=Ptemp->next;
                }

                fprintf(target_file, "MOV R%d, BP\n", y);
				fprintf(target_file, "SUB R%d, %d\n", y, z+1);
				fprintf(target_file, "MOV R%d, [R%d]\n", y, y);

                Ftemp=Ctemp->Memberfield;
                z=0;
                while(strcmp(Ftemp->name, t->left->left->varname)){
					z++;
					if(Ftemp->type==NULL)
						z++;
					Ftemp=Ftemp->next;
				}
                fprintf(target_file, "ADD R%d, %d\n", y, z);
                Ttemp=Ftemp->type;
                if(t->left->right!=NULL){
                    fprintf(target_file, "MOV R%d, [R%d]\n", y, y);
                    p=t->left->right;
                    while(p->right!=NULL){
						Ftemp=FLookup(Ttemp, p->left->varname);
						if(Ftemp==NULL){
							printf("Unknown identifier in FIELD: %s\n", p->left->varname);
							exit(0);
						}
						fprintf(target_file, "ADD R%d, %d\n", y, Ftemp->fieldIndex);
						fprintf(target_file, "MOV R%d, [R%d]\n", y, y);
						Ttemp=Ftemp->type;
						p=p->right;
					}
                    Ftemp=FLookup(Ttemp, p->left->varname);
					if(Ftemp==NULL){
						printf("Unknown identifier in FIELD: %s\n", p->mid->varname);
						exit(1);
					}
					fprintf(target_file, "ADD R%d, %d\n", y, Ftemp->fieldIndex);
				}

				fprintf(target_file, "MOV [R%d], R%d\n", y, x);
				if(t->mid!=NULL){
					Ctemp=Clookup(t->mid->varname);
					if(Ctemp==NULL){
						printf("Unknown class: %s\n", t->mid->varname);
						exit(1);
					}
				fprintf(target_file, "INR R%d\n", y);
				fprintf(target_file, "MOV [R%d], %d\n", y, 4096+8*Ctemp->class_idx);
				}

            }
            else{
                Ltemp=LLookup(t->left->left->varname);
                Ptemp=PLookup(t->left->left->varname);
                Gtemp=GLookup(t->left->left->varname);

                if( (Ltemp==NULL) && (Ptemp==NULL) && (Gtemp==NULL) ){
                    printf("Unknown variable _ASSIGN_FIELD: %s\n", t->left->varname);
                    exit(1);
                }

                if(Ltemp!=NULL){
                    Ttemp=Ltemp->type;
                    fprintf(target_file, "MOV R%d, BP\n", y);
                    fprintf(target_file, "ADD R%d, %d\n", y, Ltemp->binding);
                    fprintf(target_file, "MOV R%d, [R%d]\n", y,y);
                }
                else if(Ptemp!=NULL){
                    Ttemp=Ptemp->type;
                    fprintf(target_file, "MOV R%d, BP\n", y);
                    fprintf(target_file, "SUB R%d, %d\n", y, Ptemp->binding+2);
                    fprintf(target_file, "MOV R%d, [R%d]\n", y,y);
                }
                else if(Gtemp!=NULL){
                    Ttemp=Gtemp->type;
                    fprintf(target_file, "MOV R%d, [%d]\n", y,Gtemp->binding);
                }

                p=t->left;

                while(p->right->right!=NULL){
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
                if(Ftemp==NULL){
                    printf("Unknown identifier in FIELD: %s\n", p->right->left->varname);
                    exit(1);
                }
                fprintf(target_file, "ADD R%d, %d\n",y,Ftemp->fieldIndex);
                fprintf(target_file, "MOV [R%d], R%d\n", y,x);
            }
            
            free_register();
            free_register();
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
				printf("Unknown variable _READ: %s line 608\n", t->left->varname);
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
            x=get_register();
            if(strcmp(t->left->varname,"\0")!=0){
                Ctemp=Clookup(t->left->varname);
				z=3;
				Ptemp=Phead;
				while(Ptemp!=NULL){
					z++;
					Ptemp=Ptemp->next;
				}
				fprintf(target_file, "MOV R%d, BP\n", x);
				fprintf(target_file, "SUB R%d, %d\n", x, z+1);
				fprintf(target_file, "MOV R%d, [R%d]\n", x, x);
				Ftemp=Ctemp->Memberfield;
				z=0;
				while(strcmp(Ftemp->name, t->left->left->varname)){
					z++;
					if(Ftemp->type==NULL)
						z++;
					Ftemp=Ftemp->next;
				}
				fprintf(target_file, "ADD R%d, %d\n", x, z);
				Ttemp=Ftemp->type;
				if(t->left->right!=NULL){
					fprintf(target_file, "MOV R%d, [R%d]\n", x, x);
					p=t->left->right;
					while(p->right!=NULL){
						Ftemp=FLookup(Ttemp, p->left->varname);
						if(Ftemp==NULL){
							printf("Unknown identifier in FIELD: %s\n", p->left->varname);
							exit(1);
						}
						fprintf(target_file, "ADD R%d, %d\n", x, Ftemp->fieldIndex);
						fprintf(target_file, "MOV R%d, [R%d]\n", x, x);
						Ttemp=Ftemp->type;
						p=p->right;
					}
					Ftemp=FLookup(Ttemp, p->left->varname);
					if(Ftemp==NULL){
						printf("Unknown identifier in FIELD: %s\n", p->left->varname);
						exit(1);
					}
					fprintf(target_file, "ADD R%d, %d\n", x, Ftemp->fieldIndex);
				}
            }
            else{
                Ltemp=LLookup(t->left->left->varname);
                Ptemp=PLookup(t->left->left->varname);
                Gtemp=GLookup(t->left->left->varname);

                

                if( (Ltemp==NULL) && (Ptemp==NULL) && (Gtemp==NULL) ){
                    printf("Unknown variable _READ_FIED: %s\n", t->left->varname);
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
            }
			y = get_register();
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
			free_register();
			free_register();
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
	
	fprintf(target_file,"MOV SP, %d\n",CURR_BINDING-1);
	fprintf(target_file,"MOV BP, %d\n",CURR_BINDING);
	fprintf(target_file,"PUSH R0\n");
	fprintf(target_file,"CALL MAIN\n");
	fprintf(target_file,"INT 10\n");
}

void end_program(){
		fprintf(target_file,"INT 10");
}