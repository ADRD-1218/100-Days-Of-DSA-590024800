#include <stdio.h>

#define MAX 100

int dq[MAX];
int front = -1, rear = -1;

int isEmpty() {
    return front == -1;
}

int size() {
    if(isEmpty()) return 0;
    if(rear >= front) return rear - front + 1;
    return MAX - front + rear + 1;
}

void push_front(int x) {
    if((front == 0 && rear == MAX - 1) || (front == rear + 1)) return;

    if(isEmpty()) {
        front = rear = 0;
    } else if(front == 0) {
        front = MAX - 1;
    } else {
        front--;
    }
    dq[front] = x;
}

void push_back(int x) {
    if((front == 0 && rear == MAX - 1) || (front == rear + 1)) return;

    if(isEmpty()) {
        front = rear = 0;
    } else if(rear == MAX - 1) {
        rear = 0;
    } else {
        rear++;
    }
    dq[rear] = x;
}

void pop_front() {
    if(isEmpty()) return;

    if(front == rear) {
        front = rear = -1;
    } else if(front == MAX - 1) {
        front = 0;
    } else {
        front++;
    }
}

void pop_back() {
    if(isEmpty()) return;

    if(front == rear) {
        front = rear = -1;
    } else if(rear == 0) {
        rear = MAX - 1;
    } else {
        rear--;
    }
}

void printDeque() {
    if(isEmpty()) return;

    int i = front;
    while(1) {
        printf("%d ", dq[i]);
        if(i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        char op[20];
        scanf("%s", op);

        if(op[0] == 'p' && op[5] == 'f') {
            int x; scanf("%d", &x);
            push_front(x);
        } else if(op[0] == 'p' && op[5] == 'b') {
            int x; scanf("%d", &x);
            push_back(x);
        } else if(op[0] == 'p' && op[4] == 'f') {
            pop_front();
        } else if(op[0] == 'p' && op[4] == 'b') {
            pop_back();
        } else if(op[0] == 'f') {
            if(isEmpty()) printf("-1\n");
            else printf("%d\n", dq[front]);
        } else if(op[0] == 'b') {
            if(isEmpty()) printf("-1\n");
            else printf("%d\n", dq[rear]);
        } else if(op[0] == 'e') {
            printf("%d\n", isEmpty());
        } else if(op[0] == 's') {
            printf("%d\n", size());
        }
    }

    printDeque();

    return 0;
}