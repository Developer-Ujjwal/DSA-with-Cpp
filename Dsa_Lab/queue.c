#include <stdio.h>
#define n 20

int f = -1;
int r = -1;

void insert(int a,int* queue)
{
    if (f - r == 1)
    {
        printf("overflow");
    }
    else if (r == 4)
    {
        r = 0;
    }
    else
        r++;
    if (f == -1)
        f = 0;
        queue[r]=a;
}
void delete(int* queue)
{
    if(f==-1){
        printf("Queue is empty");
    }
    else if (f==4)
    {
        f=0;
    }
    else
    f++;
}
void display(int* queue)
{
    for (int i = f; i <=r; i++)
    {
        printf("%d ",queue[i]);
    }
}
int main()
{
    int queue[5];
    int x, a;
    while(1){
         printf("Press 1.Insert\n2.Delete\n3.Display\n");
    scanf("%d", &x);
   
    switch (x)
    {
    case 1:
        printf("Enter number to insert:");
            scanf("%d", &a);
                insert(a,queue);
        break;
    case 2:
        delete(queue);
        break;
    case 3:
        display(queue);
        break;
    default:
        printf("Enter valid Number");
        break;
    }
    }
}