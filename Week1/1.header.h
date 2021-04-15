#ifndef TREE_HEADER
#define TREE_HEADER
struct tnode{
    int val;
    char *op;
    struct tnode *left,*right;
};
struct tnode* makeLeafNode(int n);
struct tnode* makeOperatorNode(struct tnode *,char c,struct tnode *);
int evaluate(struct tnode *);
void prefix(struct tnode *);
void postfix(struct tnode *);
#endif