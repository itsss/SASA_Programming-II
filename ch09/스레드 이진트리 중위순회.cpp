#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode {
    char data;
    struct treeNode *left;
    struct treeNode *right;
    int isThreadRight;
}treeNode;

treeNode* makeRootNode(char data, treeNode* leftnode, treeNode* rightnode, int isThreadRight)
{
    treeNode* root = (treeNode *)malloc(sizeof(treeNode));
    root->data = data;
    root->left = leftnode;
    root->right = rightnode;
    root->isThreadRight = isThreadRight;
    return root;
}

void threadInorder(treeNode* root)
{
    treeNode *q, *p;
    q = root;
    if(q != NULL)
    {
        while(q->left) q = q->left;
        while(q)
        {
            printf("%3c", q->data);
            p = q;
            q = q->right;
            if(q != NULL && p->isThreadRight ==0)
            {
                while(q->left !=NULL)
                {
                    q = q->left;
                }
            }
        }
    }
}

int main()
{
    treeNode* n7 = makeRootNode('D', NULL, NULL, 0);
    treeNode* n6 = makeRootNode('C', NULL, NULL, 1);
    treeNode* n5 = makeRootNode('B', NULL, NULL, 1);
    treeNode* n4 = makeRootNode('A', NULL, NULL, 1);
    treeNode* n3 = makeRootNode('/', n6, n7, 0);
    treeNode* n2 = makeRootNode('*', n4, n5, 0);
    treeNode* n1 = makeRootNode('-', n2, n3, 0);
    
    n4->right = n2;
    n5->right = n1;
    n6->right = n3;
    
    printf("\n 스레드 이진 트리의 중위 순회 : ");
    threadInorder(n1);
    
    getchar();
    return 0;
}
