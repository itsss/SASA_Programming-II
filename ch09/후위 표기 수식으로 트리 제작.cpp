#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 100

typedef struct NODE {
    NODE *llink,*rlink;
    char val;
}node;

node *stack[N];
node *d[N];
int top=0;

void make_tree(){
    char str[101];
    scanf("%s", str);

    for(int i=0;i<strlen(str);i++){
        d[i] = (node *) malloc(sizeof(node));
        d[i]->val=str[i];
        d[i]->llink = NULL;
        d[i]->rlink = NULL;

        if(str[i]>='a' && str[i]<='z') stack[top++]=d[i];
        else{
            d[i]->rlink=stack[--top];
            d[i]->llink=stack[--top];
            stack[top++]=d[i];
        }
    }
}

void inorder(node* root) {
	if (root) {
		inorder(root->llink);
		printf("%c", root->val);
		inorder(root->rlink);
	}
}

void preorder(node* root) {
	if (root) {
		printf("%c", root->val);
		preorder(root->llink);
		preorder(root->rlink);
	}
}

int main() {
    make_tree();
    printf("inorder: ");
    inorder(stack[0]);

    printf("\npreorder: ");
    preorder(stack[0]);
    return 0;
}
