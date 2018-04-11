#include <stdio.h>
#define max_size 10

int stack[max_size], top=-1; // top = 0

//int empty()
//{
//    if(top == 1) return 1;
//    else return 0;
//}

//int full()
//{
//    if(top == max_size-1) return 1;
//    else return 0;
//}

void push(int x)
{
    if(top == max_size-1) //max_size //when int top = 0;
    {
        printf("stack is full\n");
        return;
    }
    else stack[++top] = x; //top++ //when int top = 0;
}

int pop()
{
    if(top == -1) // top == 0 //when int top = 0;
    {
        printf("stack is empty\n");
        return 0;
    }
    else return stack[top--]; //--top //when int top = 0;
}

int gettop()
{
    if(top == -1) // top == 0 //when int top = 0;
    {
        printf("stack is empty\n");
        return 0;
    }
    else return stack[top]; //stack[top-1] //when int top = 0;
}

void print()
{
    printf("Stack [ ");
    for(int i = 0; i <= top; i++) printf("%d ", stack[i]);
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
