#include <stdio.h>
#include <queue>

using namespace std;
queue<int> q;

int main()
{
    int n;
    int a[100];
    int b[100];
    int t=0;
    int sum=0;
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++) scanf("%d %d", &a[i], &b[i]);
    
    for(int i = 1; i <= 120; i++) {
        if(i%10 == 0) {
            for(int j = 0; j < 5; j++) q.push(i);
        }
        if(i == a[t]){
            if(q.size() >= b[t]) {
                for(int j = 0; j < b[t]; j++) {
                    q.pop();
                    sum++;
                }
            }
            t++;
        }
    }
    printf("%d", sum);
    return 0;
}
