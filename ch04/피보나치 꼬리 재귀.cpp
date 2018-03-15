#include <stdio.h>

long long int f(int k, long long int a, long long int b)
{
    if(k == 0) return a;
    return f(k-1, b, a+b);
}
//long long int f(int k)
//{
//    if(k <= 2) return 1;
//    return f(k-1) + f(k-2);
//}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%lld\n", f(n, 0, 1));
    //printf("%lld\n", f(n));
}

//피보나치 꼬리 재귀

