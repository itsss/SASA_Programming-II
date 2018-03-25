#include <stdio.h>

int arr[100][100];
int main()
{
    int i, j, n, diff, cnt=1;
    int s=-1, e=0;
    scanf("%d", &n);
    diff=n;
    
    while(cnt <= n*n)
    {
        for(i = 1; i <= diff; i++) arr[++s][e] = cnt++;
        diff--;
        for(i = 1; i <= diff; i++) arr[s][++e] = cnt++;
        for(i = 1; i <= diff; i++) arr[--s][e] = cnt++;
        diff--;
        for(i = 1; i <= diff; i++) arr[s][--e] = cnt++;
    }
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
