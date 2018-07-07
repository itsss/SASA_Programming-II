#include <stdio.h>
#include <algorithm>
int in[27][27], vis[27][27], dangi=0, h_num[900], cnt;
void dfs(int x, int y) {
    vis[x][y]=1; cnt++;
    if (in[x][y-1] && !vis[x][y-1]) dfs(x,y-1);
    if (in[x][y+1] && !vis[x][y+1]) dfs(x,y+1);
    if (in[x-1][y] && !vis[x-1][y]) dfs(x-1,y);
    if (in[x+1][y] && !vis[x+1][y]) dfs(x+1,y);
}

int main () {
    int n;
    scanf("%d",&n);
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            scanf("%1d", &in[i][j]);
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (in[i][j] && !vis[i][j]) {
                cnt=0;
                dfs(i,j);
                h_num[dangi]=cnt; dangi++;
            }
        }
    }
    std::sort(h_num, h_num+dangi);
    printf("%d",dangi);
    for (int i=0; i<dangi; i++) printf("\n%d", h_num[i]);
}
