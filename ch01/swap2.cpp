#include <stdio.h>

void swap(int& x, int& y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}

int main()
{
    int a = 20;
    int b = 40;
    swap(a, b);
    printf("%d %d", a, b);
}

//에일리어스를 이용한 스와핑
