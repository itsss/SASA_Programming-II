#include <stdio.h>

int cnt = 0;

void move(char from, char to, int n)
{
    //printf("Disk %d : %c to %c\n", n, from, to);
    cnt++;
}

void hanoi(int n, char from, char by, char to)
{
    if (n == 1)
    {
        move(from, to, n);
    }
    else
    {
        hanoi(n - 1, from, to, by);
        move(from, to, n);
        hanoi(n - 1, by, from, to);
    }
}

int main()
{
    int a;
    scanf("%d", &a);
    hanoi(a, 'A', 'B', 'C');
    printf("%d", cnt);
}
