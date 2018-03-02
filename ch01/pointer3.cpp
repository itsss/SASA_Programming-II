#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p, *q;
    p = (int *)malloc(sizeof(int));
    q = (int *)malloc(sizeof(int));
    *p = 5;
    *q = 20;
    p = q; //p는 q가 가리키던 메모리 공간을 가리키게 됨.
    //5를 저장하고 있는 동적할당 변수와 *p의 연결이 끊어져, 이전에 가리키던 공간은 반납되지 않은 상태로 머물게 됨.
    printf("%d %d", *p, *q);
}

//가비지
