#include <stdio.h>
#include <queue>
#define INF 9999999

using namespace std;
queue<int> Q;

int dis[27], prt[27];
int map[27][27];

void print(int k){
    if(prt[k]) print(prt[k]);
    printf("%c\n",k-1+'A');
}


int main(void)
{
    int N, M;  //N:node, M:edge
    char from, to, start, end;
    int w, tmp;

    scanf("%d %d",&N,&M);
    for(int i=1;i<=M;i++)
    {
        scanf(" %c %c %d", &from, &to, &w);
        map[from-'A'+1][to-'A'+1]=map[to-'A'+1][from-'A'+1]=w;
    }

    scanf(" %c %c", &from, &to);
    start=from-'A'+1;
    end=to-'A'+1;

    for(int i=1;i<=N;i++) dis[i]=INF;
    dis[start]=0;

    Q.push(start);
    while(!Q.empty())
    {
        tmp=Q.front();
        Q.pop();
        for(int i=1;i<=N;i++)
        {
            if(map[tmp][i] && dis[i]>dis[tmp]+map[tmp][i]){
                dis[i]=dis[tmp]+map[tmp][i];
                prt[i]=tmp;
                Q.push(i);
            }
        }
    }
    if(dis[end]==INF) {
        printf("-1");
    }
    else {
        printf("%d\n",dis[end]);
        print(end);
    }
    return 0;
}
