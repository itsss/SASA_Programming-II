#include <stdio.h>
#include <stdlib.h>

typedef struct stackNode{
    int data;
    struct stackNode *link;
}stacknode;

stacknode* top = NULL;

int empty()
{
    if(top == NULL) return 1;
    else return 0;
}

void push(int x)
{
    stacknode* temp = (stacknode *)malloc(sizeof(stacknode));
    temp -> data = x;
    temp -> link = top;
    top = temp;
}

int pop()
{
    int item;
    stacknode *temp = top;
    if(top == NULL)
    {
        printf("stack is empty\n");
        return 0;
    }
    else
    {
        item = temp -> data;
        top = temp -> link;
        free(temp);
        return item;
    }
}

int gettop()
{
    if(top == NULL)
    {
        printf("stack is empty\n");
        return 0;
    }
    else
    {
        return top->data;
    }
}

void print()
{
    stacknode* p = top;
    printf("Stack [ ");
    while(p)
    {
        printf("%d ", p->data);
        p = p -> link;
    }
    printf("]\n");
}

int main()
{
    int n;
    printf("명령어 개수: ");
    scanf("%d", &n);
    printf("1:push 2:pop 3:gettop 4:exit \n");
    for(int i = 0; i < n; i++)
    {
        int comm = 0, item;
        scanf("%d", &comm);
        if(comm == 1)
        {
            scanf("%d", &item);
            push(item);
            print();
        }
        else if(comm == 2)
        {
            item = pop();
            printf("Pop_item: %d, ", item);
            print();
        }
        else if(comm == 3)
        {
            item = gettop();
            printf("gettop_item: %d , ", item);
            print();
        }
        else if(comm == 4)
        {
            return 0;
        }
        else printf("명령어 입력 오류");
    }
}
