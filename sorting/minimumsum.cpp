#include <iostream>
using namespace std;
void sort(int *arr, int n)
{
    for (int i = 1; i < n; i++)
    {

        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
            else
                break;
        }
    }
}
int main()
{
    int arr[] = {5, 5, 3, 5, 7, 3, 2, 4, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    sort(arr, n);

    int number1 = 0;
    for (int i = 0; i < n; i++)
    {
        number1 = number1 * 10;
        number1 = number1 + arr[i];
    }
    for (int i = n - 1; i >= 1; i++)
    {
        if (arr[i - 1] != arr[i])
        {
            swap(arr[i], arr[i - 1]);
            break;
        }
    }
    int number2 = 0;
    for (int i = 0; i < n; i++)
    {
        number2 = number2 + arr[i];
        if (i < n - 1)
            number2 = number2 * 10;
    }
    int sum = number1 + number2;
    cout << sum;
}