#include<iostream>
using namespace std;
int main(){
    int arr[]={3,5,1,4,2};
    int n=5;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<n-1;i++)
    {
        bool count= false;
        for(int j=0;j<n-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                count = true;
            }
        }
        if(count==false)
        break;
    }
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}