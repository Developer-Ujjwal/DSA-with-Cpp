#include<iostream>
#include<climits>
using namespace std;
int main(){
int arr[]={5,1,-1,4,5};                    
int n=5;
for(int ele:arr)                        //for each
{
    cout<<ele<<" ";
}
cout<<endl;
for(int i=1;i<n;i++)              
{

    for(int j=i-1;j>=0;j--)
    {
        if(arr[j]>arr[j+1])
        swap(arr[j],arr[j+1]);
        else break;
    }
}
for(int ele:arr)
{
    cout<<ele<<" ";
}
}
