#include <iostream>
#include <climits>
#include <vector>
using namespace std;
int main()
{
    int arr[] = {5, 1, 7, 4, 5};

    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    int x = 0;
    for (int i = 0; i < 5; i++)
    {
        int min = INT_MAX;
        int mindx = -1;
        for (int j = 0; j < 5; j++)
        {
            if (arr[j] <= 0)
                continue;
            else
            {
                if (min > arr[j])
                {
                    min = arr[j];
                    mindx = j;
                }
            }
        }
        arr[mindx] = -x;
        x++;
    }
    for (int i = 0; i < 5; i++)
    {
        arr[i]=-arr[i];
        cout << arr[i] <<" ";
    }
}