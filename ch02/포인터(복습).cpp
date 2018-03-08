#include <stdio.h>
#include <stdlib.h>

int main()
{
    // 정적 할당 vs 동적 할당
    int *p;
    int *q;
    p = (int *)malloc(sizeof(int));
    int a = 10;
    q = &a;
    printf("p=%d q=%d\n", p, &q);
    
    *p = 11;
    *q = 21;
    printf("*p = %d *q = %d a = %d &a = %d &(*p)=%d\n", *p, *q, a, &a, &(*p));
    
    int x = 20, y = 10;
    int *px = &x;
    int *py = &y;
    printf("%d %d\n", x+*py, *&x * *px); //20+10, 20*20
    
    free(p);
    p=NULL; //NULL Pointer
    //printf("%d %d \n", p, *p); //Error(!!!)
    
    int *pa, *pb;
    pa = (int *)malloc(sizeof(int));
    *pa = 5;
    pb = pa;
    free(pa); //Dangling Pointer 존재하지 않는 공간을 가르킴
    
    pa = (int *)malloc(sizeof(int));
    pb = (int *)malloc(sizeof(int));
    
    *pa = 5;
    *pb = 20;
    p = q; //Garbage
}
