#include <stdio.h>
#include <stdbool.h>

int main()
{
    int search_list[] = {5, 6, 7, 8, 9, 10, 11, 15, 18, 20};
    int n, i, elements_count;
    elements_count = sizeof(search_list) / sizeof(int);

    // Display the array elements
    printf("Array Elements: ");
    for (i = 0; i < elements_count; i++)
        printf("%d ", search_list[i]);
    printf("\n\n");

    printf("Enter a value to search: ");
    scanf("%d", &n);

    int low, high, mid;
    low = 0;
    high = elements_count - 1;
    bool flag = false;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (search_list[mid] == n)
        {
            printf("The target value %d is found at position %d", n, (mid + 1));
            flag = true;
            break;
        }
        else if (n < search_list[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    if (flag == false)
        printf("Element not found");

    return 0;
}
