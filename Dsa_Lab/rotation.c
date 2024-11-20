#include<stdio.h>
int main(){
    int arr[]={1,3,5,8,0,4,4};
    int n=sizeof(arr)/sizeof(arr[0]);

        for(int j=0;j<n-1;j++)
        {
            int temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
        }
        for(int i=0;i<n;i++)
        {
            printf("%d ",arr[i]);
        }
    
}