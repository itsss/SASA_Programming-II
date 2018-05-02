#include <stdio.h>
#include <stdlib.h>

typedef struct queuenode{
    int data;
    struct queuenode *link;
}qnode;

qnode *front = NULL, *rear = NULL;

int empty() {
    if(front == NULL) return 1;
    else return 0;
}

void enqueue(int x){
    qnode *newnode = (qnode *)malloc(sizeof(qnode));
    newnode -> data = x;
    newnode -> link = NULL;
    
    if(empty()) {
        front = newnode;
        rear = newnode;
    }
    else {
        rear -> link = newnode;
        rear = newnode;
    }
}

int dequeue() {
    qnode *old = front;
    int item;
    if(empty()) {
        printf("queue is empty\n");
        return 0;
    }
    else {
        item = old -> data;
        front = front -> link;
        if(front == NULL) rear = NULL;
        free(old);
        return item;
    }
}

int peek() {
    if(empty()) {
        printf("queue is empty\n");
        return 0;
    }
    else return front->data;
}

void print() {
    printf("linked queue [ ");
    qnode *temp = front;
    while(temp) {
        printf("%d ", temp->data);
        temp = temp -> link;
    }
    printf("]\n");
}

int main()
{
    int n;
    printf("명령어 개수: ");
    scanf("%d", &n);
    printf("1:enqueue   2:dequeue  3:peek  4:exit \n");
    for (int i = 0; i < n; i++) {
        int comm=0, item;
        scanf("%d", &comm);
        if (comm==1) {
            scanf("%d", &item);
            enqueue(item); print();
        }
        else if (comm==2) {
            item =dequeue(); printf("delete_item: %d ,  ", item); print();
        }
        else if (comm==3) {
            item=peek();
            printf("peek_item: %d ,  ", item); print();
        }
        else if (comm==4) {
            return 0;
        }
        else {
            printf("명령어 입력 오류 \n");
        }
    }
    return 0;
}
