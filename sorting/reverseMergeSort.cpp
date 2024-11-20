#include<iostream>
#include<vector>
using namespace std;
void merge(vector<int>& v,vector<int> &a, vector<int> &b)
{
    int i=0;
    int j=0;
    int k=0;
    int n1=a.size();
    int n2=b.size();
    while(i<n1 && j<n2)
    {
        if(a[i]>=b[j])
        {
            v[k]=a[i];
            k++;
            i++;
        }
        else 
        {
            v[k]=b[j];
            j++;
            k++;
        }
    }
    while(i<n1)
    {
        v[k]=a[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        v[k]=b[j];
        j++;
        k++;
    }

}
void mergeSort(vector<int> &v)
{
    
    int n=v.size();
    if(n==1) return;
    int n1=n/2;
    int n2=n-(n/2);
    
    vector<int> a(n1);
    vector<int> b(n2);
    for(int i=0;i<n1;i++)
    {
        a[i]=v[i];
    }
     for(int i=0;i<n2;i++)
    {
        b[i]=v[i+n1];
    }
    mergeSort(a);
    mergeSort(b);
merge(v,a,b);

}
int main(){
        vector<int> v;
    v.push_back(5);
    v.push_back(1);
    v.push_back(6);
    v.push_back(4);
    v.push_back(9);
    v.push_back(0);
    mergeSort(v);
    for(int i = 0; i < 6 ; i++)
    {
        cout << v[i]<<endl;
    }
}