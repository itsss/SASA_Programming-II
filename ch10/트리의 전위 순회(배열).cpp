#include <stdio.h>
char str[20009];

void f(int x)
{
    printf("%c", str[x]);
    if(str[2*x+1]) f(2*x+1);
    if(str[2*x+2]) f(2*x+2);
}

int main()
{
    scanf("%s", str);
    f(0);
}
