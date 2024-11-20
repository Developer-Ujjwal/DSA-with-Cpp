#include <stdio.h>
#include <stdbool.h>
int main()
{
    int elements_count;
    int n, result;
    int search_list[] = {3, 1, 9, 8, 7, 12, 56, 23, 89};
    elements_count = sizeof(search_list) / sizeof(int);

    printf("Enter a value to search: ");
    scanf("%d", &n);
    bool flag = false;
    for (int i = 0; i < elements_count; i++)
    {
        if (n == search_list[i])
        {
            printf("The target value %d is found at position %d\n", n, i + 1);
            flag = true;
        }
    }
    if (flag == false)
    {
        printf("Element not found");
    }
    return 0;
}
