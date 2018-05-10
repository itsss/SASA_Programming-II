#include <stdio.h>
#define INF 9999999
#define max_size 10000

int queue[max_size], front=-1, rear=-1;

int empty()
{
    if(front == rear) return 1;
    else return 0;
}

int enqueue(int x)
{
    if(rear == max_size - 1)
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

int dis[27]; //최단거리 (A까지의 최단거리, B까지의 최단거리 등등...)
int map[27][27];

int main()
{
    int N, M; //N:node, M:edge
    char from, to, start, end;
    int w, tmp;
    scanf("%d %d", &N, &M);
    for(int i = 1; i <= M; i++)
    {
        scanf(" %c %c %d", &from, &to, &w);
        map[from-'A'+1][to-'A'+1] = map[to-'A'+1][from-'A'+1] = w;
    }
    scanf(" %c %c", &from, &to);
    start = from -'A'+1;
    end = to -'A'+1;
    
    for(int i = 1; i<=N;i+=1) dis[i] = INF;
    dis[start] = 0;
    
    enqueue(start);
    while(!empty())
    {
        tmp = queue[front+1];
        dequeue();
        for(int i = 1; i <= N; i++)
        {
            if(map[tmp][i] && dis[i] > dis[tmp] + map[tmp][i])
            {
                dis[i] = dis[tmp] + map[tmp][i];
                enqueue(i);
            }
        }
    }
    if(dis[end] == INF) printf("-1");
    else printf("%d", dis[end]);
    
}
