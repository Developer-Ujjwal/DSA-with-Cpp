#include<stdio.h>
int main(){
    int arr[]={1,3,5,8,0,4,4};
    int count[10]={0};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++)
    {
        count[arr[i]]++;
    }
    for(int i=0;i<10;i++)
    {
        printf("Count of %d in the array is %d\n",i,count[i]);
    }
}