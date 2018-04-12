#include <stdio.h>
#include <stack>
using namespace std;
stack<int> st;

int main()
{
    int n, in, pos=1;
    int index[500001];
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &in);
        while(!st.empty() && st.top() < in)
        {
            st.pop();
            pos--;
        }
        if(st.empty() || st.top() >= in)
        {
            st.push(in);
            pos++;
            index[pos] = i+1; //기둥 번호 삽입
        }
        if(st.size() == 1) printf("0 ");
        else printf("%d ", index[pos-1]);
    }
}
