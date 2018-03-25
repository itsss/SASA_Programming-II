#include <stdio.h>

int main()
{
    int n, num=0, arr[50][50];
    scanf("%d", &n);
    int row = 0, col = n/2;
    while(num <= n*n)
    {
        arr[row][col] = ++num;
        if(num % n == 0) row++;
        else
        {
            col++; row--;
            if(col == n) col = 0;
            if(row == -1) row = n-1;
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

//#include <stdio.h>
//
//int main()
//{
//    int arr[50][50], i, j, num=0, n;
//    scanf("%d", &n);
//    for(i=0; i<n; i++)
//    {
//        for(j=0; j<n; j++)
//        {
//            arr[(2*i-j+n)%n][(n/2-i+j+n)%n]=++num;
//        }
//    }
//    for(i = 0; i < n; i++)
//    {
//        for(j = 0; j < n; j++)
//        {
//            printf("%d ", arr[i][j]);
//        }
//        printf("\n");
//    }
//}


