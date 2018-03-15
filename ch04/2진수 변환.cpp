#include <stdio.h>

void solve(int k)
{
    if(k/2) solve(k/2);
    printf("%d", k%2);
}

int main()
{
    int n;
    scanf("%d", &n);
    solve(n);
}
