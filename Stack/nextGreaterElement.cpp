#include <iostream>
#include <stack>
using namespace std;
int main()
{
    int arr[]={5,15,10,8,6,12,9,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    stack<int> st;
    int ans[n];
    ans[n-1]=-1;
    st.push(arr[n-1]);
    for(int i=n-2;i>=0;i--)
    {
        while(!st.empty()&& st.top()<arr[i]) st.pop();
        if(st.empty()) ans[i]=-1;
        else ans[i]=st.top();
        st.push(arr[i]);
    }
    for(int i=0;i<n;i++)
    {
        cout<<ans[i]<<" ";
    }
}