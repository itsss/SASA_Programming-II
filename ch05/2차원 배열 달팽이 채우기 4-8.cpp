#include <stdio.h>

int main()
{
    int cnt, n, m, arr[100][100];
    scanf("%d %d", &n, &m);
    cnt = n*m;
    int x=n, y=1;
    while(cnt >= 1)
    {
        while(arr[x][y] == 0 && x > 0)
        {
            arr[x--][y] = cnt++;
        }
        x++, y++;
        
        while(arr[x][y] == 0 && y <= m)
        {
            arr[x][y++] = cnt--;
        }
        y--, x++;
        while(arr[x][y] == 0 && x <= n)
        {
            arr[x++][y] = cnt++;
        }
        x--, y--;
        while(arr[x][y] == 0 && y > 0)
        {
            arr[x][y--] = cnt--;
        }
        x++, y--;
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
