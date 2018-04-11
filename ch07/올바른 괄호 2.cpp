#include <stdio.h>
#include <stack>

using namespace std;

int main()
{
    stack<char> st;
    int matched=1;
    char in[50001];
    scanf("%s", in);
    for(int i = 0; in[i] != '\0'; i++)
    {
        if(in[i] == '(') st.push(in[i]);
        else if(in[i] == ')')
        {
            if(!st.empty()) st.pop();
            else{
                matched =0;
                break;
            }
        }
    }
    if(st.size() == 0 && matched) printf("good");
    else printf("bad");
}

