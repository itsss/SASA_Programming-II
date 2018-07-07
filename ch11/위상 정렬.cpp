#include <stdio.h>
#include <queue>
int arr[201][201],chk[201];
std::queue<int> q;

int main(void)
{
    int i, j, v, n, cnt=0;
    scanf("%d %d",&v, &n);
    for(i=0;i<n;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        arr[a][b]=1,arr[b][a]=-1;
    }

    while(cnt!=v)
    {
        for(i=1;i<=v;i++)
        {
            if(!chk[i])
            {
                bool flag=0;
                for(j=1;j<=v;j++)
                    if(arr[i][j]==-1)
                    {
                        flag=1;
                        break;
                    }
                if(!flag) break;
            }
        }
        if(i>v)
        {
            printf("-1");
            return 0;
        }
        q.push(i);
        for(int a=1;a<=v;a++) arr[a][i]=arr[i][a]=0;
        chk[i]=1;
        cnt++;
    }

    while(!q.empty()) {
        printf("%d\n",q.front()); q.pop();
    }
}
