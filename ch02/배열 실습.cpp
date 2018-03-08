#include <stdio.h>
#include <stdlib.h>

int SumUp(int A[], int size)
{
    int Sum = 0;
    *(A+2) = 10;
    for(int i = 0; i < size; i++)
    {
        Sum += A[i];
        printf("%d ", Sum);
    }
    return Sum;
}

int main()
{
    int Total;
    int Score[5] = {98, 92, 88, };
    Total = SumUp(Score, 3);
    printf("%d", Total);
}
//200
