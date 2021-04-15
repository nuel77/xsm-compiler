#include"1.header.h"
#include<stdlib.h>
#include<stdio.h>

struct tnode* makeLeafNode(int n){
    struct tnode *newNode;
    newNode= (struct tnode *)(malloc(sizeof(struct tnode)));
    newNode->op=NULL;
    newNode->val=n;
    newNode->left= NULL; newNode->right=NULL;
   
    return newNode;
}

struct tnode* makeOperatorNode(struct tnode* left,char c,struct tnode* right){
    struct tnode *newNode;
    newNode= (struct tnode *)(malloc(sizeof(struct tnode)));
    newNode->op=(char*)(malloc(sizeof(char)));
    *(newNode->op)=c; //will give segmentation fault if not used!
    newNode->val=0;
    newNode->left= left; newNode->right=right;
    return newNode;
}
int evaluate(struct tnode * node){
    if(node->op==NULL) return node->val;
    else{
        char ch= *(node->op);
        switch (ch)
        {
        case'+': return evaluate(node->left)+evaluate(node->right);
            
        case'-': return evaluate(node->left)-evaluate(node->right);
                
        case'*': return evaluate(node->left)*evaluate(node->right);
                
        case'/': return evaluate(node->left)/evaluate(node->right);
        }
    }
}
void prefix(struct tnode *node){
	if(node->op==NULL){
		printf(" %d",node->val);
	}
	else{
		printf(" %c",*(node->op));
		prefix(node->left);
		prefix(node->right);
	}   
}

void postfix(struct tnode *node){
	if(node->op==NULL){
		printf(" %d",node->val);
	}
	else{
        prefix(node->left);
		prefix(node->right);
		printf(" %c",*(node->op));
	}   
}

