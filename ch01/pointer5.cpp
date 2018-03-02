#include <stdio.h>

void fcn(int *pi)
{
    *pi = 5;
}

int main()
{
    int n = 3;
    fcn(&n);
    printf("%d", n);
}

//참조 호출 (Call by Reference)
/*
 다음 프로그램의 실행 결과는?
 
 호출함수인 main에서 넘기는 것은, 변수 n이 아니고 변수 n의 주소 값이다.
 이 주소 값(포인터 값)이 값 호출에 의해 fcn 함수의 *pi로 복사되어 들어간다.
 이후, *pi => 포인터의 값에 5를 할당하여, 연결된 n도 5가 된다.
 
 따라서, 실행 결과는 5가 된다.
 
 */
