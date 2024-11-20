#include <stdio.h>
#define N 50
int queue[N];
int f = -1;
int r = -1;
void enqueue()
{
    int x;
    if (r == N - 1)
    {
        printf("Queue overflow: Cannot insert more elements.\n");
    }
    else
    {
        if (f == -1)
        {
            f = 0;
        }
        printf("Enter item to insert: ");
        scanf("%d", &x);
        r++;
        queue[r] = x;
        printf("%d inserted into the queue.\n", x);
    }
}
int dequeue()
{
    if (f == -1 || f > r)
    {
        printf("Queue underflow: Cannot remove elements.\n");
        return -1;
    }
    int element = queue[f];
    f++;
    if (f > r)
    {
        f = r = -1;
    }
    return element;
}
void display()
{
    if (r == -1)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        printf("Elements in the queue:\n");
        for (int i = f; i <= r; i++)
        {
            printf("%d\n", queue[i]);
        }
        printf("\n");
    }
}
int main()
{
    int ch;
    do
    {
        printf("Choose the operation you want to perform\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit");
        printf("Enter the operation : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            enqueue();
            break;
        case 2:
            printf("Dequeued element: %d\n", dequeue());
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting the program.\n");
            break;
        default:
            printf("Invalid choice. Try again.\n");
            break;
        } 
    }while (ch != 0);
    return 0;
}