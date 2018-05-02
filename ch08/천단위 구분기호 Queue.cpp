#include <stdio.h>
#include <queue>

using namespace std;

int main()
{
    int n, cnt=0;
    char s[201];
    queue<char> q;
    scanf("%d %s", &n, s);
    
    for(int i = 0; i < n; i++, cnt++){
        q.push(s[i]);
    }
    
    while(!q.empty()){
        printf("%c", q.front());
        q.pop();
        cnt--;
        if(cnt%3==0 && cnt > 0) printf(",");
    }
    printf("\n");
    return 0;
}
