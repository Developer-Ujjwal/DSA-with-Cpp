#include<iostream>
using namespace std;
int main(){
    int arr[]={1,2,2,3,3,3,3,4,4,4,4,5,6,7};
    int x=3;
    int n=sizeof(arr)/sizeof(arr[0]);
    int low=0, high=n-1, mid;
    bool flag=false;
    while(low<=high)
    {
        mid=low+(high-low)/2;
        if(arr[mid]==x)
        {
            if(arr[mid+1]!=x)
            {
                cout<<mid;
                flag=true;
                break;
            }
            else low=mid+1;
        }
        else if(arr[mid]>x) high=mid-1;
        else if(arr[mid]<x) low=mid+1;
    }
    if(flag==false)
    {
        cout<<"Target not found";
    }
}