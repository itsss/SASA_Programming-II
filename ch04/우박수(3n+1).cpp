#include <stdio.h>

void solve(int n)
{
    if(n==1) ;
    else
    {
        if(n%2 == 1) solve(3*n+1);
        else solve(n/2);
    }
    printf("%d\n", n);
}

int main()
{
    int n;
    scanf("%d", &n);
    solve(n);
}
