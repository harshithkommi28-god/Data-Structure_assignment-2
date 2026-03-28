#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int x) {
    if(rear == MAX-1)
        printf("Queue Full\n");
    else {
        if(front == -1) front = 0;
        queue[++rear] = x;
        printf("Document added\n");
    }
}

void dequeue() {
    if(front == -1)
        printf("Queue Empty\n");
    else {
        printf("Printing document: %d\n", queue[front]);
        front++;
        if(front > rear)
            front = rear = -1;
    }
}

void display() {
    if(front == -1)
        printf("No pending documents\n");
    else {
        printf("Pending: ");
        for(int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}

int main() {
    int ch, x;

    while(1) {
        printf("\n1.Add 2.Print 3.Display 4.Exit\n");
        scanf("%d", &ch);

        switch(ch) {
            case 1: scanf("%d", &x); enqueue(x); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: return 0;
        }
    }
}