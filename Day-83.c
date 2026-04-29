#include <stdio.h>

int main()
{
    int n, i, j, minIndex, temp;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);

    for(i = 0; i < n; i++)
    {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("\nStarting Selection Sort...\n");

    for(i = 0; i < n - 1; i++)
    {
        minIndex = i;

        for(j = i + 1; j < n; j++)
        {
            if(arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }

    printf("\nSorted Array:\n");

    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}