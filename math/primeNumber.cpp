#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int n=7;
    bool prime=1;
    for(int i=2;i<sqrt(n);i++)
    {
        if(n%i==0){ prime=0;
        break;
        }
    }
    if(prime==0){
        cout<<"Not Prime";
    }
    else cout<<"prime";

}