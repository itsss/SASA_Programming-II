#include <stdio.h>

int main()
{
    int n, arr[100][100];
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            arr[i][j] = n*i+(i%2 ? j+1 : n-j);
        }
    }
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
//2차원 배열 지그재그 채우기 2-2
