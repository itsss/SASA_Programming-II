#include <stdio.h>
#include <stack>

using namespace std;
int main()
{
    int n, in;
    stack<int> st;
    long long int sum = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &in);
        while(!st.empty() && st.top() < in)
            st.pop();
        if(st.empty() || st.top() > in)
            st.push(in);
        sum += st.size() - 1;
    }
    printf("%lld", sum);
}
