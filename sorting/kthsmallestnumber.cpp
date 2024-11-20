#include<bits/stdc++.h>
using namespace std;
int partition(vector<int> &v, int si, int ei)
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
int kthSmallest(vector<int> v,int k,int si,int ei)
{
    int pivot=partition(v,si,ei);
    if(pivot==k-1) return v[pivot];
    else if(pivot>k-1)  return kthSmallest(v,k,si,pivot-1);
    else return kthSmallest(v,k,pivot+1,ei);
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
    cout<<kthSmallest(v,3,0,v.size()-1);
}