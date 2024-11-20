#include <stdio.h>
#include <stdlib.h>

int n, top = -1;
int stack[10];
void push(int x)
{
    if (top == n)
        return;
    stack[++top] = x;
}

int pop()
{
    if (top == -1)
        return -1;
    return stack[top--];
}

void display()
{
    for (int i = 0; i <= top; i++)
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main()
{
    n=10;

    push(12);
    push(24);
    push(98);
    display();

    int popped = pop();
    printf("The popped element is %d\n", popped);
    display();

    return 0;
}
