#include <stdio.h>
#include <stack>

using namespace std;

char a[101], b[101];
stack<int> sta, stb, stsum;

int main()
{
    int carry = 0;
    scanf("%s[^\n]", a);
    scanf("%s[^\n]", b);
    
    for(int i = 0; a[i]; i++) sta.push(a[i]-'0');
    for(int i = 0; b[i]; i++) stb.push(b[i]-'0');
    
    for(int i = 0; !sta.empty() || !stb.empty(); i++)
    {
        int tmpa=0, tmpb=0;
        if(!sta.empty())
        {
            tmpa = sta.top();
            sta.pop();
        }
        if(!stb.empty())
        {
            tmpb = stb.top();
            stb.pop();
        }
        stsum.push((tmpa+tmpb+carry)%10);
        carry = (tmpa + tmpb + carry) / 10;
    }
    if(carry) stsum.push(1);
    
    while(!stsum.empty())
    {
        printf("%d", stsum.top());
        stsum.pop();
    }
}


