#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    unsigned long long F1, F2;
    F1=1;F2=1;
    for(int i=3;i<=n;i++)
    {
        unsigned long long tmp=F2;
        F2+=2*F1;
        F1=tmp;
    }
    printf("%llu",F2);
}
