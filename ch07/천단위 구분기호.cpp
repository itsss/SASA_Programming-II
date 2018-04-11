#include <stdio.h>
#include <stack>

using namespace std;

int main()
{
    int n;
    char s[201];
    stack<char> st;
    scanf("%d %s", &n, s);
    for(int i = n-1, c=1; i >= 0; i--, c++)
    {
        st.push(s[i]);
        if(c%3==0 && c!=n) st.push(',');
    }
    while(!st.empty())
    {
        printf("%c", st.top());
        st.pop();
    }
    printf("\n");
    return 0;
}
