#include <stdio.h>
#include <stack>

using namespace std;

int main()
{
    char inp[201];
    stack<int> nums;
    
    scanf("%[^\n]s", &inp);
    for(int i = 0; inp[i]; i++)
    {
        if(inp[i] >= '0' && inp[i] <= '9')
        {
            int k = 0;
            while(inp[i] >= '0' && inp[i] <= '9')
            {
                k *= 10;
                k += inp[i] - '0';
                i++;
            }
            nums.push(k);
            continue;
        }
        else if(!(inp[i] == '*' || inp[i] == '+' || inp[i] == '-')) continue;
        
        int v = nums.top();
        nums.pop();
        int w = nums.top();
        nums.pop();
        
        if(inp[i] == '*') v = w * v;
        else if(inp[i] == '+') v = w + v;
        else if(inp[i] == '-') v = w - v;
        
        nums.push(v);
    }
    printf("%d", nums.top());
    
}
