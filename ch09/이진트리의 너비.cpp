#include <stdio.h>
#define MAX 1000001
int cnt;
int left[MAX], right[MAX], max[MAX], min[MAX];

void solve(int node, int dep)
{
    if(left[node] != -1) solve(left[node], dep+1);
    if(max[dep] < cnt) max[dep] = cnt;
    if(min[dep] > cnt) min[dep] = cnt;
    cnt++;
    if(right[node] != -1) solve(right[node], dep+1);
}

int main()
{
    int n, t;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &t);
        scanf("%d %d", &left[t], &right[t]);
        max[i] = -999999999;
        min[i] = 999999999;
    }
    
    cnt = 1;
    int a, b=-999999999;
    solve(1, 1);
    
    for(int i = 1; i <= n; i++)
    {
        if(max[i] < 0) break;
        t = max[i] - min[i];
        if(b < t)
        {
            b = t;
            a = i;
        }
    }
    printf("%d %d", a, b+1);
}
