/*
 트리의 순회 활용
 n개의 정점을 갖는 이진 트리의 정점에 1이상의 자연수가 번호의 중복 없이 매겨져 있다. 이와 같은 이진 트리의 인오더와 포스트오더가 주어졌을 때, 프리오더를 구하는 프로그램을 작성하시오.

 <입력>
 첫째 줄에 n(1≤n≤100)이 주어진다. 다음 줄에는 인오더를 나타내는 n개의 자연수가 주어지고, 그 다음 줄에는 같은 식으로 포스트오더가 주어진다.
 
 3
 1 2 3
 1 3 2
 
 <출력>
 첫째 줄에 프리오더를 출력한다.
 
 2 1 3

 */

#include <stdio.h>
int in[101], post[101];
int tree[10001], loc, cnt, n;

void maketree(int start, int end, int loc){
    if(start>end || tree[loc]) return;
    tree[loc]=post[n-cnt];
    cnt++;
    if(start == end) return;
    
    for(int i = 1; i <= n; i++) {
        if(in[i] == tree[loc]) {
            maketree(i+1, end, loc*2+1);
            maketree(start, i-1, loc*2);
        }
    }
}

void f(int x) {
    printf("%d ", tree[x]);
    if(tree[2*x]) f(2*x);
    if(tree[2*x+1]) f(2*x+1);
}

int main(){
    int start;
    scanf("%d", &n);
    for(int i=1;i<=n;i++) scanf("%d", &in[i]);
    for(int i=1;i<=n;i++) scanf("%d", &post[i]);
    
    maketree(1,n,1);
    
    f(1);
    return 0;
}
