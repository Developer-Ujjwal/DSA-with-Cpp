#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
int pivot(vector<int> &v, int si, int ei)
{
    int count=0;                                                        
    int pivot = v[si];
    for (int i = si+1; i <= ei; i++)
    {
        if (v[i] <= pivot)
            count++;
    }
    int pi=count+si;
    swap(v[si], v[pi]);
    int i = si;
    int j = ei;
    while (i < pi && j > pi)
    {
        if (v[i] <= pivot)
            i++;
        if (v[j] > pivot)
            j--;
        else if (v[i] > pivot && v[j] <= pivot)
        {
            swap(v[i], v[j]);
            i++;
            j--;
        }
    }
    return pi; 
}
void quickSort(vector<int> &v, int si, int ei)
{
    if (si >= ei)
        return;
    int pi = pivot(v, si, ei);
    quickSort(v, si, pi - 1);
    quickSort(v, pi + 1, ei);
}
int main()
{
    vector<int> v;
    v.push_back(5);
    v.push_back(1);
    v.push_back(6);
    v.push_back(4);
    v.push_back(9);
    v.push_back(0);
    for (int i = 0; i < 6; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    quickSort(v, 0, 5);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}