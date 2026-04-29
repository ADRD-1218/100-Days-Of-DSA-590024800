#include <stdio.h>

int main()
{
    int n, x, i;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d sorted elements:\n", n);
    for(i = 0; i < n; i++)
    {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Enter target value: ");
    scanf("%d", &x);

    int left = 0, right = n - 1, mid;
    int lower = n, upper = n;

    while(left <= right)
    {
        mid = (left + right) / 2;

        if(arr[mid] >= x)
        {
            lower = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    left = 0;
    right = n - 1;

    while(left <= right)
    {
        mid = (left + right) / 2;

        if(arr[mid] > x)
        {
            upper = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    printf("\nLower Bound Index = %d\n", lower);
    printf("Upper Bound Index = %d\n", upper);

    return 0;
}