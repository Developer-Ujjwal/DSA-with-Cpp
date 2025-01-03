#include<iostream>
#include<vector>
using namespace std;
class stack{
    public:
    vector<int> v;
    void push(int val)
    {
       v.push_back(val);
    }
    void pop()
    {
        if(v.size()==0)
        {
            cout<<"Stack is Empty";
            return;
        }
        v.pop_back();
    }
    int top(){
        if(v.size()==0)
        {
            cout<<"Stack is empty";
            return -1;
        }
        return v[v.size()-1];
    }
    int size()
    {
        return v.size();
    }
    void display()
    {
        if(v.size()==0)
        {
            cout<<"Stack is empty";
            return;
        }
        for(int i=v.size()-1;i>=0;i--)
        {
            cout<<v[i]<<" ";
        }
    }
};
int main(){
    stack st;
    cout<<st.top()<<endl;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);
    cout<<st.size()<<endl;
    cout<<st.top()<<endl;
    st.display();

}
