#include <stdio.h>
#define MAX 20000

typedef struct node{
    char name;
    struct node *left;
    struct node *right;
}node;

node inp[MAX];
int idx = 0;
int next(char data)
{
    int count = 0;
    while(inp[count].name != NULL)
    {
        if(inp[count].left == NULL)
        {
            inp[idx].name = data;
            inp[count].left = &inp[idx];
            idx++;
            return 0;
        }
        
        else if(inp[count].right == NULL)
        {
            inp[idx].name = data;
            inp[count].right = &inp[idx];
            idx++;
            return 0;
        }
        else count++;
    }
    if(inp[count].name == NULL) {
        inp[idx++].name = data;
    }
    return -1;
}

void print()
{
    int n = 2;
    while(n < MAX) {
        for(int i = (n / 2) - 1; i < n - 1; i++) printf("%c ", inp[i].name);
        printf("\n");
        n *= 2;
    }
}

void preorder(node* root) {
    if(root != NULL) {
        printf("%c", root->name);
        preorder(root -> left);
        preorder(root -> right);
    }
}

void inorder(node* root) {
    if(root != NULL) {
        inorder(root->left);
        printf("%c", root->name);
        inorder(root->right);
    }
}

void postorder(node* root) {
    if(root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%c", root->name);
    }
}

int main()
{
    char data[MAX];
    scanf("%s", data);
    
    for(int i = 0; data[i]; i++) {
        next(data[i]);
    }
    
    printf("\n binary tree output: \n\n");
    print();
    preorder(&inp[0]);
    printf("\n중위 순회 출력: ");
    inorder(&inp[0]);
    printf("\n후위 순회 출력: ");
    postorder(&inp[0]);
}

