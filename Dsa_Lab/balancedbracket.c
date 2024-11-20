#include <stdio.h>
int main()
{
    char equation[50];
    int x = 0, i = 0;
    printf("Enter an equation : ");
    scanf("%s", equation);
    while (equation[i] != '\0')
    {
        if (equation[i] == '(')
        {
            x++;
        }
        else if (equation[i] == ')')
        {
            x--;
            if (x < 0)
                break;
        }
        i++;
    }
    if (x == 0)
    {
        printf("Equation is balanced");
    }
    else
    {
        printf("Equation is unbalanced");
    }
    return 0;
}