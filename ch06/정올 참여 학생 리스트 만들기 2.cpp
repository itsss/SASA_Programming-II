﻿#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int no;
    char name[10];
    struct Node * next;
}node;

node * head = NULL;

void insertSt(node p)
{
    node *t, *pre = NULL;
    node *n = (node *)malloc(sizeof(int));
    *n = p;

    //t->no 현재노드, p.no 다음노드
    for(t=head; t!=NULL && t -> no < p.no; pre=t, t=t->next); // t-> no < p.no (등호를 넣지 않으면 수험번호가 이미 입력된 경우 같은 수험번호의 맨 앞에 데이터 삽입 가능)
    n -> next = t;
        
    if(pre) pre->next=n; //이전 노드의 존재 여부 체크
    else head = n;
}

void deleteSt(node p)
{
    node *t, *pre=NULL;
    for(t=head; t!=NULL && t->no < p.no; pre=t, t=t->next);
    if(t && t->no == p.no)
    {
        if(pre) pre->next = t->next;
        else head = t->next;
        free(t);
    }
}

int main()
{
    int n, loc[5] = {};
    char c;
    node t;
    
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf(" %c %d %s", &c, &t.no, t.name);
        if(c == 'I') insertSt(t);
        else if(c == 'D') deleteSt(t);
        else printf("입력 오류");
    }
    for(int i = 0; i < 5; i++)
    {
        scanf("%d", &loc[i]);
    }
    
    int cnt = 0;
    for(node *t = head; t!=NULL; t=t->next)
    {
        cnt++;
        for(int i = 0; i < 5; i++)
        {
            if(loc[i] == cnt)
            {
                printf("%d %s\n", t->no, t->name);
            }
        }
    }
    return 0;
}

