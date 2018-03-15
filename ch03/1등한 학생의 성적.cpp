#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char name[10];
    int s1;
    int s2;
    int s3;
}student;

int main()
{
    int n;
    int max = -999, loc = 0, rank2 = 1, rank3 = 1;
    scanf("%d", &n);
    student *p = (student *)malloc(sizeof(student)*n);
    //student p[n];
    for(int i = 0; i < n; ++i)
    {
        scanf("%s %d %d %d", p[i].name, &p[i].s1, &p[i].s2, &p[i].s3);
        if(p[i].s1 > max)
        {
            max = p[i].s1; //1등만 골라냄
            loc = i;
        }
    }
    for(int i = 0; i < n; ++i) //1등의 위치를 기반으로, 나머지 과목의 성적을 구해냄
    {
        if(p[i].s2 > p[loc].s2) rank2++;
        if(p[i].s3 > p[loc].s3) rank3++;
    }
    printf("%s %d %d", p[loc].name, rank2, rank3);
    free(p);
    return 0;
}
