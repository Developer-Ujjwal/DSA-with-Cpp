#include <iostream>
using namespace std;
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n - 1; i++)
    {
        bool count = false;
        for (int j = n - 1; j >= 1 + i; j--)
        {
            if (arr[j - 1] < arr[j])
            {
                swap(arr[j], arr[j - 1]);
                count = true;
            }
        }
        if (count == false)
            break;
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

//  for(int j=0;j<n-1-i;j++)
//         {
//             if(arr[j]<arr[j+1])
//             {
//                 swap(arr[j],arr[j+1]);
//                 count = true;
//             }
//         }
       