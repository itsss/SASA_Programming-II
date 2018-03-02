#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main()
{
    int *p;
    p = (int *)malloc(sizeof(int)); //(C) int 타입의 필요한 size만큼 동적 변수 할당
    *p = 15;
    printf("%d\n", *p); //(C) print *p
    free(p); //(C) 동적 변수 해제(반환)
    p = NULL; //p를 따라가지 않도록, NULL 설정
    
    int *k;
    k = new int; //(C++) int 타입의 필요한 size만큼 동적 변수 할당
    *k = 15;
    cout << *k << endl; //(C++) print *k
    delete k; //(C++) 동적 변수 해제(반환)
    k = NULL; //k를 따라가지 않도록, NULL 설정
    
}

