#include <stdio.h>
#include <string.h>

#define MAX 100

int table[MAX];
int m;

// Initialize table
void init() {
    for (int i = 0; i < m; i++) {
        table[i] = -1;
    }
}

// Hash function
int hash(int key) {
    return key % m;
}

// Insert with detailed prints
void insert(int key) {
    int h = hash(key);
    printf("\nInserting %d (hash = %d)\n", key, h);

    for (int i = 0; i < m; i++) {
        int index = (h + i * i) % m;
        printf("Trying index = (%d + %d^2) %% %d = %d\n", h, i, m, index);

        if (table[index] == -1) {
            table[index] = key;
            printf("Inserted at index %d\n", index);
            return;
        } else {
            printf("Collision at index %d\n", index);
        }
    }

    printf("Hash table full, cannot insert %d\n", key);
}

// Search with detailed prints
void search(int key) {
    int h = hash(key);
    printf("\nSearching %d (hash = %d)\n", key, h);

    for (int i = 0; i < m; i++) {
        int index = (h + i * i) % m;
        printf("Checking index = (%d + %d^2) %% %d = %d\n", h, i, m, index);

        if (table[index] == key) {
            printf("FOUND\n");
            return;
        }

        if (table[index] == -1) {
            printf("NOT FOUND\n");
            return;
        }
    }

    printf("NOT FOUND\n");
}

// Display table
void display() {
    printf("\nHash Table:\n");
    for (int i = 0; i < m; i++) {
        if (table[i] == -1)
            printf("Index %d: EMPTY\n", i);
        else
            printf("Index %d: %d\n", i, table[i]);
    }
}

int main() {
    int q;
    char op[10];
    int key;

    scanf("%d", &m);   // table size
    scanf("%d", &q);   // operations

    init();

    for (int i = 0; i < q; i++) {
        scanf("%s %d", op, &key);

        if (strcmp(op, "INSERT") == 0) {
            insert(key);
        } else if (strcmp(op, "SEARCH") == 0) {
            search(key);
        }
    }

    display();

    return 0;
}