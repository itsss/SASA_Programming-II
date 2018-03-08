#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *str;
    int a, b;
    str = (char*) malloc(100);
    scanf("%s", str);
    scanf("%d %d", &a, &b);
    for(int i = a-1; i < b; i++)
    {
        printf("%c", *(str+i));
    }
    free(str);
}

//포인터 (부분 문자열)
