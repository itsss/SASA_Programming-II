#include <stdio.h>
#include <stdlib.h>

int main()
{
    void *ptr; //ptr is declared as Void pointer
    char cnum = 'a';
    int inum = 10;
    float fnum = 3.14;
    
    ptr = &cnum; // ptr has address of character data
    printf("%d %c\n", ptr, *(char*)ptr);
    
    ptr = &inum; //ptr has address of integer data
    printf("%d %d\n", ptr, *(int*)ptr);
    
    ptr = &fnum; //ptr has address of float data
    printf("%d %f\n", ptr, *(float*)ptr);
}
