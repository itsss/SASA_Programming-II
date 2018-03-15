#include <stdio.h>

int chk[6000];

void solve(int k)
{
    int res = k;
    while(k)
    {
        res=res+k%10;
        k=k/10;
    }
    chk[res]++;
}

int main()
{
    int a, b, sum=0;
    scanf("%d %d", &a, &b);
    for(int i = 1; i <= b; i++) solve(i);
    for(int i = a; i <= b; i++)
    {
        if(chk[i] == 0) sum = sum + i;
    }
    printf("%d", sum);
}
