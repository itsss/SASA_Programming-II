#include <stdio.h>
#include <queue>

int arr[1001][1001]={0}, sx,sy, fx,fy, tx,ty, nx,ny, n;
int dx[8]={2,-2,2,-2,1,-1,1,-1};
int dy[8]={1,1,-1,-1,2,2,-2,-2};
using namespace std;
queue<int> Qx, Qy;


int main(){
    scanf("%d", &n);
    scanf("%d %d", &sx,&sy);
    scanf("%d %d", &fx,&fy);
    arr[sx][sy]=1;
    Qx.push(sx); Qy.push(sy);
    while(!Qx.empty() && !Qy.empty()){
        nx=Qx.front(); Qx.pop();
        ny=Qy.front(); Qy.pop();
        if(nx==fx && ny==fy) break;
        for(int i=0; i<8; i++){
            tx=nx+dx[i]; ty=ny+dy[i];
            if(tx>=1&&tx<=n&&ty>=1&&ty<=n && arr[tx][ty]==0){
                Qx.push(tx); Qy.push(ty);
                arr[tx][ty]=arr[nx][ny]+1;
            }
        }
    }
    printf("%d",arr[fx][fy]-1);
}
