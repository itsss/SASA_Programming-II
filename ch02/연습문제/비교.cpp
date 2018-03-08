#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;
    scanf("%d", &a);
    int *arr;
    arr = (int*)malloc(sizeof(int)*a+1);
    
    for(int i = 0; i < a; i++)
    {
        scanf("%d", arr+i);
    }
    
    for(int i = 0; i < a; i++)
    {
        printf("%d: ", i+1);
        for(int j = 0; j < a; j++)
        {
            if(i == j) continue;
            if(*(arr+i) > *(arr+j)) printf("> ");
            else if(*(arr+i) < *(arr+j)) printf("< ");
            else printf("= ");
        }
        printf("\n");
    }
    return 0;
}

//비교

