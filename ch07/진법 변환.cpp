#include <stdio.h>
#include <stack>

using namespace std;
stack<char> st;

void ton(int n, int d)
{
    while(n)
    {
        st.push(n%d);
        n=n/d;
    }
    printf("%d ", d);
    while(!st.empty())
    {
        printf("%d", st.top());
        st.pop();
    }
    printf("\n");
}

int main()
{
    int i, n;
    scanf("%d", &n);
    ton(n, 2);
    printf("8 %o\n", n);
    printf("16 %X\n", n);

}

