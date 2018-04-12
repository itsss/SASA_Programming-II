#include <stdio.h>
#include <stack>

char str[201];

using namespace std;
stack<int> st;

int main()
{
    int n, in, ord = 1;
    int pos = 0;
    
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &in);
        st.push(in);
        str[pos++] = 'S';
        while(st.top() == ord)
        {
            str[pos++] = 'X';
            ord++;
            st.pop();
            if(st.empty()) break;
        }
    }
    if(!st.empty()) printf("IMPOSSIBLE");
    else printf("%s", str);
}
