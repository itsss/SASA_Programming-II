#include <stdio.h>
int arr[502][502];
int n;
void floyd() {
    int i, j, k;
    for (k = 0; k < n; ++k) {
        for (i = 1; i <=n; ++i) {
            for (j = 1; j <=n; ++j) {
                arr[i][j] = arr[i][j] | (arr[i][k + 1] && arr[k + 1][j]);
            }
        }
    }
}

int main(void) {
    int m;
    int cnt=0;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++) {
        int a,b;
        scanf("%d %d",&a,&b);
        arr[a][b]=1;
    }

    floyd();

    for(int i=1;i<=n;i++) {
        int in=0,out=0;
        for(int j=1;j<=n;j++)  if(arr[j][i]==1) in++;
        for(int j=1;j<=n;j++)  if(arr[i][j]==1) out++;
        if((in+out)==n-1) cnt++;
    }
    printf("%d",cnt);
}
