#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char name[10];
    int score;
}student;

void swaps(student &a, student &b)
{
    student tmp;
    tmp = a;
    a = b;
    b = tmp;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    student *st = (student *)malloc(sizeof(student)*n);
    //student st[101]; //student st[n];
    for(int i = 0; i < n; i++)
    {
        scanf("%s %d", st[i].name, &st[i].score);
    }
    for(int i = 0; i < n-1; i++)
    {
        for(int j = 0; j < n-1-i; j++)
        {
            if(st[j].score < st[j+1].score)
            {
                swaps(st[j], st[j+1]);
            }
        }
    }
    for(int i = 0; i < m; i++)
    {
        printf("%s\n", st[i].name);
    }
//    for(int i = 0; i < n; i++)
//    {
//        printf("%s %d\n", st[i].name, st[i].score);
//    }
}

//성적표 출력
