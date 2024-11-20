#include<iostream>
#include<climits>
using namespace std;
int main(){
int arr[]={5,4,1,3,2};                      //min find karenge first member se swap kr denge
int n=5;
for(int ele:arr)                        //for each
{
    cout<<ele<<" ";
}
cout<<endl;
for(int i=0;i<n-1;i++)              
{
    int min=INT_MAX;
    int mindx=-1;
    //finding minimum
    for(int j=i;j<n;j++)
    {
        if(arr[j]<min)
        {
            min=arr[j];
            mindx=j;
        }
    }
    swap(arr[i],arr[mindx]);
}
for(int ele:arr)
{
    cout<<ele<<" ";
}
}

