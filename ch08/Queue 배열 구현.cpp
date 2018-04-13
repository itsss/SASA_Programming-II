#include <stdio.h>
#define max_size 100

int queue[max_size], front=-1, rear=-1;

int empty()
{
    if(front == rear) return 1;
    else return 0;
}

int full()
{
    if(rear == max_size-1) return 1;
    else return 0;
}

int enqueue(int x)
{
    if(full())
    {
        printf("Queue is full");
        return 0;
    }
    else return queue[++rear] = x;
}

int dequeue()
{
    if(empty())
    {
        printf("Queue is Empty");
        return 0;
    }
    else return queue[++front];
}

int peek()
{
    if(empty())
    {
        printf("Queue is Empty");
        return 0;
    }
    else return queue[front + 1];
}

void print()
{
    printf("Queue [ ");
    for(int i = front + 1; i <= rear; i++) printf("%d ", queue[i]);
    printf("]\n");
}


int main()
{
    int n;
    printf("명령어 개수: ");
    scanf("%d", &n);
    printf("1:enqueue 2:dequeue 3:peek 4:exit \n");
    for(int i = 0; i < n; i++)
    {
        int comm = 0, item;
        scanf("%d", &comm);
        if(comm == 1)
        {
            scanf("%d", &item);
            enqueue(item);
            print();
        }
        else if(comm == 2)
        {
            item = dequeue();
            printf("Pop_item: %d, ", item);
            print();
        }
        else if(comm == 3)
        {
            item = peek();
            printf("peek: %d , ", item);
            print();
        }
        else if(comm == 4)
        {
            return 0;
        }
        else printf("명령어 입력 오류");
    }
}
