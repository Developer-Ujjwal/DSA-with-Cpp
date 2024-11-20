#include <stdio.h>
#include <stdio.h>
#define MAX 10
int myQueue[MAX];
int F = 0, R = -1;
void insert()
{
    if (R == MAX - 1)
    {
        printf("Queue is overflow\n");
    }
    else
    {
        int element;
        printf("Enter the element to be inserted: ");
        scanf("%d", &element);
        R++;
        myQueue[R] = element;
    }
}
void delete()
{
    if (F > R)
    {
        printf("Queue is empty\n");
    }
    else
    {
        int element = myQueue[F];
        printf("The deleted element: %d\n", element);
        F++;
    }
}
void displayQueue()
{
    if (F > R)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("Queue Elements: ");
        for (int i = F; i <= R; i++)
        {
            printf("%d ", myQueue[i]);
        }
        printf("\n");
    }
}
int main()
{
    int choice;
    do
    {
        printf("Choose the operation you want to perform\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. exit\n ");
        printf("Enter your operation: ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            insert();
        }
        else if (choice == 2)
        {
            delete ();
        }
        else if (choice == 3)
        {
            displayQueue();
        }
        else if (choice == 4)
        {
            printf("Exited Successfully\n");
        }
        else
        {
            printf("Invalid Choice!!!\n");
        }
    } while (choice != 4);
    return 0;
}
