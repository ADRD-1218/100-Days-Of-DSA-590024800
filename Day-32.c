#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int x) {
    if(top < MAX - 1) {
        stack[++top] = x;
    }
}

void pop() {
    if(top >= 0) {
        top--;
    }
}

int main() {
    int n, m;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        push(x);
    }

    scanf("%d", &m);

    for(int i = 0; i < m; i++) {
        pop();
    }

    for(int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }

    return 0;
}