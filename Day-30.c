#include <stdio.h>
#include <stdlib.h>

struct node {
    int coeff;
    int exp;
    struct node* next;
};

struct node* insert(struct node* head, int coeff, int exp) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->coeff = coeff;
    newnode->exp = exp;
    newnode->next = NULL;

    if(head == NULL) return newnode;

    struct node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;

    return head;
}

void display(struct node* head) {
    struct node* temp = head;

    while(temp != NULL) {
        if(temp->exp == 0)
            printf("%d", temp->coeff);
        else if(temp->exp == 1)
            printf("%dx", temp->coeff);
        else
            printf("%dx^%d", temp->coeff, temp->exp);

        if(temp->next != NULL)
            printf(" + ");

        temp = temp->next;
    }
}

int main() {
    int n, coeff, exp;
    struct node* head = NULL;

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d %d", &coeff, &exp);
        head = insert(head, coeff, exp);
    }

    display(head);

    return 0;
}