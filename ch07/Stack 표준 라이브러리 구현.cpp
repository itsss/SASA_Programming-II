#include <stdio.h>
#include <stack>

using namespace std;

int main()
{
    int n;
    stack<int> st;
    printf("명령어 개수: ");
    scanf("%d", &n);
    printf("1:push 2:pop 3:stack_print(초기화됨) 4:exit\n");
    for(int i = 0; i < n; i++)
    {
        int comm = 0, item;
        scanf("%d", &comm);
        if(comm == 1)
        {
            scanf("%d", &item);
            st.push(item);
        }
        else if(comm == 2)
        {
            if(st.empty()) printf("stack is empty\n");
            else
            {
                printf("Pop_item: %d , \n", st.top());
                st.pop();
            }
        }
        else if(comm == 3)
        {
            while(!st.empty())
            {
                item = st.top();
                printf("%d ", item);
                st.pop();
            }
            printf("\n");
        }
        else if(comm == 4) return 0;
        else printf("명령어 오류");
    }
}
