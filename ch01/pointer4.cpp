#include <stdio.h>

void fcn(int i)
{
    i = 5;
}

int main()
{
    int n = 3;
    fcn(n);
    printf("%d", n);
}

// 값 호출 (Call By Value)
/*
 다음 프로그램의 실행 결과는?
 
 main 함수에서 변수 n의 값을 3으로 할당하였다. 이후, fcn 함수를 호출하였다.
 fcn 함수에서 main 함수에서 넘긴 파라미터 n을 i로 받아와, 이곳에 5를 할당하였다.
 fcn 함수 실행이 끝나고, main 함수로 되돌아 왔을 때 n의 값을 출력하면,
 그 결과는 여전히 이전에 메인 함수에서 할당한 3이 된다.
 
 */
