#include<iostream>
using namespace std;
int main(){
    int arr[]={0,0,0,0,0,0,1,1,1,1,1};
    int x=1;
    int n=sizeof(arr)/sizeof(arr[0]);
    int low=0, high=n-1, mid;
    bool flag=false;
    while(low<=high)
    {
        mid=low+(high-low)/2;
        if(arr[mid]==x)
        {
            if(arr[mid-1]!=x)
            {
                cout<<(n-1)-mid+1;
                flag=true;
                break;
            }
            else high=mid-1;
        }
        else if(arr[mid]>x) high=mid-1;
        else if(arr[mid]<x) low=mid+1;
    }
    if(flag==false)
    {
        cout<<"Target not found";
    }
}