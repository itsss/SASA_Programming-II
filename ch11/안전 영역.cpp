#include <stdio.h>
int arr[102][102];
int temp[102][102];
int n;

void dfs(int i,int j) {
    temp[i][j]=0;
    if(temp[i+1][j]) dfs(i+1,j);
    if(temp[i-1][j]) dfs(i-1,j);
    if(temp[i][j+1]) dfs(i,j+1);
    if(temp[i][j-1]) dfs(i,j-1);
    return;
}

int main(void) {
    int sum=0;
    int max=0;
    int smax=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) {
            scanf("%d", &arr[i][j]);
            if(arr[i][j]>max) max=arr[i][j];
        }

    for(int k=0;k<=max;k++) {
        sum=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++) {
                if(arr[i][j]<=k) temp[i][j]=0;
                else temp[i][j]=arr[i][j]-k;
            }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++) {
                if(temp[i][j]) {
                    dfs(i,j);
                    sum++;
                }
            }
        if(smax<sum) smax=sum;
    }
    printf("%d",smax);
}
