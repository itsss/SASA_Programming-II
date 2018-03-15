#include <stdio.h>
#include <math.h>

typedef struct
{
    int x, y;
}point;

int main()
{
    point p1, p2;
    double i;
    scanf("%d %d %d %d", &p1.x, &p1.y, &p2.x, &p2.y);
    i = sqrt(pow((p1.x-p2.x), 2) + pow((p1.y-p2.y), 2));
    printf("%.2f", i);
}

// 두 점 간의 거리 (구조체)
