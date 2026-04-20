#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = top;
    top = newNode;
}

int pop() {
    if(top == NULL) return 0;
    struct Node* temp = top;
    int val = temp->data;
    top = top->next;
    free(temp);
    return val;
}

int main() {
    char exp[200];
    fgets(exp, sizeof(exp), stdin);

    int i = 0;

    while(exp[i] != '\0') {
        if(exp[i] == ' ') {
            i++;
            continue;
        }

        if(isdigit(exp[i])) {
            int num = 0;
            while(isdigit(exp[i])) {
                num = num * 10 + (exp[i] - '0');
                i++;
            }
            push(num);
        } else {
            int b = pop();
            int a = pop();
            int res;

            if(exp[i] == '+') res = a + b;
            else if(exp[i] == '-') res = a - b;
            else if(exp[i] == '*') res = a * b;
            else if(exp[i] == '/') res = a / b;

            push(res);
            i++;
        }
    }

    printf("%d", pop());

    return 0;
}