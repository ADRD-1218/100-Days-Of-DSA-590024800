#include <stdio.h>

int main()
{
    int n;

    printf("Enter a non-negative number: ");
    scanf("%d", &n);

    if(n == 0 || n == 1)
    {
        printf("Integer Square Root = %d", n);
        return 0;
    }

    int left = 1, right = n, mid, ans = 0;

    printf("\nStarting Binary Search...\n");

    while(left <= right)
    {
        mid = left + (right - left) / 2;

        if(mid <= n / mid)
        {
            ans = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    printf("\nInteger Square Root of %d = %d", n, ans);

    return 0;
}