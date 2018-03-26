#include <stdio.h>

typedef struct{
    int no;
    char name[10];
}student;

void insertSt(student *p, student t, int *n)
{
    int i, k;
    for(i = *n-1; i >= 0 && p[i].no > t.no; i--);
    k = i+1;
    for(int i = *n; i > k; i--) p[i] = p[i-1]; //맨 뒤에서부터 k위치까지 한칸씩 밈
    p[k]=t;
    *n=*n+1;
}

void deleteSt(student *p, student t, int *n)
{
    int i, k=-1;
    for(i=*n-1; i >= 0 && p[i].no >= t.no; i--)
    {
        if(p[i].no == t.no) k = i;
    }
    if(k >= 0)
    {
        for(int i = k; i < *n; i++)
        {
            p[i] = p[i+1];
        }
        *n = *n - 1;
    }
}

int main()
{
    int n, len=0;
    char c;
    student t;
    scanf("%d", &n);
    student st[100];
    for(int i = 0; i < n; i++)
    {
        scanf(" %c %d %s", &c, &t.no, t.name);
        if(c == 'I') insertSt(st, t, &len);
        else if(c == 'D') deleteSt(st, t, &len);
        else printf("입력 오류");
    }
    for(int i = 0; i < len; i++)
    {
        printf("%d번째 학생 : %d %s\n", i+1, st[i].no, st[i].name);
    }
}
