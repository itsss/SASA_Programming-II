#include <stdio.h>
#include <queue>
int arr[200][200];
int visited[200];

using namespace std;
queue<int> q;
int cnt = -1; //처음에 방문하는 출발점은 0이라, cnt를 -1로 초기화

void visit(int n) {
    q.push(n);
    visited[n] = 1;
    cnt++;
}

int main()
{
    int n,m;
    int in1, in2;
    scanf("%d %d", &n, &m);
    for(int i=0; i<m; i++) {
        scanf("%d %d", &in1, &in2);
        arr[in1][in2] = arr[in2][in1] = 1;
    }
    visit(1);
    while(!q.empty()) {
        for(int k = 1; k <= n; k++) {
            if(arr[q.front()][k] == 1 && !visited[k])
            {
                visit(k);
            }
        }
        q.pop();
    }
    printf("%d", cnt);
}
