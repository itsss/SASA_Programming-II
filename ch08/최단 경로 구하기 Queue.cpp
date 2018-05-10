#include <stdio.h>
#include <queue>
#define INF 9999999

using namespace std;
queue<int> q;

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
    
    q.push(start);
    while(!q.empty())
    {
        tmp = q.front();
        q.pop();
        for(int i = 1; i <= N; i+=1)
        {
            if(map[tmp][i] && dis[i] > dis[tmp] + map[tmp][i])
            {
                dis[i] = dis[tmp] + map[tmp][i];
                q.push(i);
//                for(int x = 1; x <= N; x++) printf("%d ", dis[x]);
//                 printf("\n");
            }
        }
    }
    if(dis[end] == INF) printf("-1");
    else printf("%d", dis[end]);
    
}
