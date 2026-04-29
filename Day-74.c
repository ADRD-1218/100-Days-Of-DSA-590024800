#include <stdio.h>
#include <string.h>

int main() {
    int n;
    char names[100][50];
    char unique[100][50];
    int count[100] = {0};
    int uniqueCount = 0;

    printf("Enter number of votes: ");
    scanf("%d", &n);

    printf("Enter candidate names:\n");

    for (int i = 0; i < n; i++) {
        scanf("%s", names[i]);

        int found = -1;

        for (int j = 0; j < uniqueCount; j++) {
            if (strcmp(unique[j], names[i]) == 0) {
                found = j;
                break;
            }
        }

        if (found == -1) {
            strcpy(unique[uniqueCount], names[i]);
            count[uniqueCount]++;
            uniqueCount++;
        } else {
            count[found]++;
        }
    }

    int maxVotes = count[0];
    int winner = 0;

    for (int i = 1; i < uniqueCount; i++) {
        if (count[i] > maxVotes) {
            maxVotes = count[i];
            winner = i;
        } 
        else if (count[i] == maxVotes) {
            if (strcmp(unique[i], unique[winner]) < 0) {
                winner = i;
            }
        }
    }

    printf("Winner: %s %d", unique[winner], maxVotes);

    return 0;
}