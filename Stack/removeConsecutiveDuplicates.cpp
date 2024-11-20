#include<iostream>
#include<stack>
using namespace std;
int main()
{
    string s="aaabbccdeffggg";
    stack<char> st;
    string ans="";
    int n=s.length();
    
    st.push(s[0]);
    for(int i=1;i<n;i++)
    {
        if( st.top()!=s[i]) st.push(s[i]);
    }
    while(!st.empty())
    {
        ans=st.top()+ans;
        st.pop();
    }
    cout<<ans<<endl;

    
}