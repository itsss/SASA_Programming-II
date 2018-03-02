#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p, *q;
    p = (int *)malloc(sizeof(int));
    *p = 15;
    q = p; //포인터 q도 p와 동일한 메모리 공간을 가르킴
    free(p); //이후, p가 그 공간을 반납하고
    p = NULL; //오류 방지를 위해 자신을 NULL로 만듬
    *q = 30; //그러나, q는 여전히 이미 반납된 이전의 메모리 공간을 가르키는 상태
    printf("%d %d", *p, *q); //오류 발생!
}

//댕글랭 포인터
