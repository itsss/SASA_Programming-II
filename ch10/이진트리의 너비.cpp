#include <stdio.h>

int tree[1001][2], cnt=1, wid[1001][2];

void inOrder(int k, int lv) {
    if(tree[k][0]!=-1) inOrder(tree[k][0], lv+1);
    if(wid[lv][0]==0) wid[lv][0] = cnt;
    wid[lv][1]=cnt++;
    if(tree[k][1]!=-1) inOrder(tree[k][1], lv+1);
}

int main()
{
    int n, no, left, right;
    scanf("%d", &n);
    
    for(int i=0;i<n;i++){
        scanf("%d %d %d", &no, &left, &right);
        tree[no][0]=left;
        tree[no][1]=right;
    }
    inOrder(1, 1);
    int lv,w=0;
    for(int i = 1; i < 1001; i++) {
        if(wid[i][0] == 0) break;
        int tmp = wid[i][1]-wid[i][0]+1;
        if(w<tmp) w=tmp, lv=i;
    }
    printf("%d %d", lv, w);
}
