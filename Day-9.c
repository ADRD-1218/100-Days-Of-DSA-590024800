#include <stdio.h>
#include <string.h>

void reverse(char str[], int left, int right) {
    if(left >= right) return;

    char temp = str[left];
    str[left] = str[right];
    str[right] = temp;

    reverse(str, left + 1, right - 1);
}

int main() {
    char str[1000];
    scanf("%s", str);

    int len = strlen(str);

    reverse(str, 0, len - 1);

    printf("%s", str);

    return 0;
}