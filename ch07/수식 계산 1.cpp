#include <stdio.h>
#include <stack>

using namespace std;
stack<int> st;

int main()
{
    char str[201];
    scanf("%[^\n]s", str);
    
    for(int i = 0; str[i]; i++)
    {
        if(str[i] >= '0' && str[i] <= '9')
        {
            int n = 0;
            while(str[i] >= '0' && str[i] <= '9') //10 이상일 때
            {
                n *= 10;
                n += str[i] - '0';
                i++;
            }
            st.push(n);
            continue;
        }
        else if(str[i] == '*' || str[i] == '+' || str[i] == '-') //str에 *, +, - 기호가 들어오면
        {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            if(str[i] == '*') st.push(b*a);
            if(str[i] == '+') st.push(b+a);
            if(str[i] == '-') st.push(b-a);
        }
    }
    printf("%d", st.top());
}

