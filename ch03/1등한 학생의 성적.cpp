#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char name[30]; //학생의 이름
    int s1, s2, s3; //1~3번째 과목
}student;

int main()
{
    int n, max=-999, loc=0, rank2=1, rank3=1;
    scanf("%d", &n); //n을 입력받는다.
    student *st = (student *)malloc(sizeof(student)*n); //구조체 동적할당
    for(int i = 0; i < n; i++)
    {
        //학생의 정보 입력
        scanf("%s %d %d %d", st[i].name, &st[i].s1, &st[i].s2, &st[i].s3);
        if(st[i].s1 > max) //첫 번째 과목을 1등한 학생의 위치를 구한다.
        {
            max = st[i].s1; //1등한 학생 구별용으로 사용.
            loc = i; //1등한 학생의 위치
        }
    }
    for(int i = 0; i < n; i++)
    { //1등한 학생의 두번째, 세번째 과목의 석차도 알아보자.
        if(st[i].s2 > st[loc].s2) rank2++;
        if(st[i].s3 > st[loc].s3) rank3++;
    }
    //첫 번째 과목을 1등한 학생의 이름과, 두번째, 세번째 과목의 석차를 구분하여 출력.
    printf("%s %d %d", st[loc].name, rank2, rank3);
}
