#include <stdio.h>

void swap(int *x, int *y)
{
    int temp;
    temp = *x; //x, y 변수에 지정된 주소로 값을 swap
    *x = *y;
    *y = temp;
}

int main()
{
    int a = 20;
    int b = 40;
    swap(&a, &b); //a, b 지역변수의 주소를 swap 함수로 넘겨줌
    printf("%d %d", a, b);
}

//포인터를 이용한 swaping
