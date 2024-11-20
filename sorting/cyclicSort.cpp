#include <iostream>
#include<vector>
using namespace std;
void cyclicSort(vector<int> &v){
    int n=v.size();
    int i=0;
    while(i<n)
    {
        if(v[i]==i) i++;
        else swap(v[i],v[v[i]]);
    }
}
int main()
{
    vector<int> v;
    v.push_back(5);
    v.push_back(1);
    v.push_back(2);
    v.push_back(4);
    v.push_back(3);
    v.push_back(0);
    cyclicSort(v);
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
}
