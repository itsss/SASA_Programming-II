#include <stdio.h>
#define max_size 5

int queue[max_size], front=0, rear=0; //front, rear 0 초기화

int empty()
{
    if(front == rear) return 1;
    else return 0;
}

int full()
{
    if((rear+1)%max_size == front) return 1; //(rear+1)%max_size == front로 조건 수정
    else return 0;
}

int enqueue(int x)
{
    if(full())
    {
        printf("Queue is full\n");
        return 0;
    }
    else return queue[(++rear) % max_size] = x;
}

int dequeue()
{
    if(empty())
    {
        printf("Queue is Empty\n");
        return 0;
    }
    else return queue[(++front) % max_size];
}

int peek()
{
    if(empty())
    {
        printf("Queue is Empty\n");
        return 0;
    }
    else return queue[(front+1) % max_size];
}

void print()
{
    printf("Queue [ ");
    int start = (front+1) % max_size;
    int end = (rear+1) % max_size;
    for(int i = start; i != end; i=(i+1)%max_size) printf("%d ", queue[i]);
    printf("]\n"); //start, end, for문 수정
}


int main()
{
    int n;
    printf("명령어 개수: ");
    scanf("%d", &n);
    printf("1:enqueue 2:dequeue 3:peek 4:exit \n");
    for(int i = 0; i < n; i++)
    {
        int comm = 0, item=0;
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

