#include <stdio.h>
int tree[10001], loc;

void maketree(int in){
    int loc = 1;
    while(tree[loc]) {
        if(in < tree[loc]) loc = loc * 2;
        else loc = loc*2+1;
    }
    tree[loc] = in;
}

void postorder(int x) {
    if(tree[2*x]) postorder(2*x);
    if(tree[2*x+1]) postorder(2*x+1);
    printf("%d ", tree[x]);
}

int main() {
    int n, in;
    scanf("%d", &n);
    for(int i=0;i<n;i++) {
        scanf("%d", &in);
        maketree(in);
    }
    postorder(1);
    return 0;
}
