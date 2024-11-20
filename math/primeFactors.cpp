#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int n=22;
    for(int i=2;i<=n;i++)
    {
        if(n%i==0)
        {
            cout<<i<<" ";
            while(n%i==0) n/=i;
        } 
    }
}