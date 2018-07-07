#include <stdio.h>

int cheese[110][110];
int chk[110][110];
int cnt[110];
int r, c, num;

void air(int i,int j){
    if(i>=1 && i<=r && j>=1 && j<=c){
        if(!chk[i-1][j] && !cheese[i-1][j])  { chk[i-1][j]=-1; air(i-1,j);  }
        if(!chk[i][j-1] && !cheese[i][j-1])  { chk[i][j-1]=-1; air(i,j-1);  }
        if(!chk[i][j+1] && !cheese[i][j+1])  { chk[i][j+1]=-1; air(i,j+1);  }
        if(!chk[i+1][j] && !cheese[i+1][j])  { chk[i+1][j]=-1; air(i+1,j);  }
    }
}

void melt(){
    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++)
            if(cheese[i][j]==1)
                if(chk[i-1][j]==-1||chk[i+1][j]==-1||chk[i][j-1]==-1||chk[i][j+1]==-1){
                    cheese[i][j]=0;
                    num--;
                }
}

int main(void){
    int cnt[110], t=0;
    scanf("%d %d",&r,&c);
    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++){
            scanf("%d",&cheese[i][j]);
            num+=cheese[i][j];
        }

    while(1){
        cnt[++t]=num;
        if(num==0) break;
        for(int i=1;i<=r;i++)
            for(int j=1;j<=c;j++)
                chk[i][j]=0;
        chk[1][1]=-1;
        air(1,1);
        melt();
    }
    printf("%d\n%d",t-1,cnt[t-1]);
}
