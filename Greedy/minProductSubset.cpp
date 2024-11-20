#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int minProduct(vector<int> arr)
{
    int n=arr.size();
    int cn=0,cp=0,cz=0;
    int positiveProduct=1;
    int negativeProduct=1;
    int minPos=INT_MAX;
    int maxNeg=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==0) cz++;
        if(arr[i]>0)
        {
             cp++;
             positiveProduct*=arr[i];
             minPos=min(minPos,arr[i]);
        }
        if(arr[i]<0)
        {
            negativeProduct*=arr[i];
            cn++;
            maxNeg=max(maxNeg,arr[i]);
        }
    }
    if(cn==0)
    {
        if(cz==0) return minPos;
        else return 0;

    }
    else if(cn%2==0) return  (negativeProduct/maxNeg)*positiveProduct;
    else return negativeProduct*positiveProduct;
}
int main()
{
    vector<int> arr={-1,1,-1,1,-4,5,6,0};
    cout<<minProduct(arr);

}
