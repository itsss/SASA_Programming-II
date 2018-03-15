#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct
{
    int x, y;
}point;

int main()
{
    int n;
    double sum = 0;
    scanf("%d", &n);
    point *p = (point *)malloc(sizeof(point)*n);
    scanf("%d %d", &p[0].x, &p[0].y);
    
    for(int i = 1; i < n; i++)
    {
        scanf("%d %d", &p[i].x, &p[i].y);
        sum += sqrt(pow((p[i-1].x-p[i].x), 2) + pow((p[i-1].y - p[i].y), 2));
    }
    printf("%.2f", sum);
}

//여러 점간의 거리 (구조체)
