#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, k;
    scanf("%d", &n);

    struct Node *head = NULL, *temp = NULL, *newNode;

    for(int i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    scanf("%d", &k);

    if(n == 0 || k == 0) {
        temp = head;
        while(temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        return 0;
    }

    k = k % n;

    struct Node* tail = head;
    int len = 1;

    while(tail->next != NULL) {
        tail = tail->next;
        len++;
    }

    tail->next = head;

    int steps = len - k;
    struct Node* newTail = head;

    for(int i = 1; i < steps; i++) {
        newTail = newTail->next;
    }

    head = newTail->next;
    newTail->next = NULL;

    temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}