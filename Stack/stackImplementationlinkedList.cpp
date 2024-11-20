#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node* next;
    Node(int value)
    {
        val=value;
        next=nullptr;
    }
};
class stack{
    public:
    Node* head;
    int s;
    stack()
    {
        head=nullptr;
        s=0;
    }
    void push(int value)
    {
        Node* insert= new Node(value);
        insert->next=head;
        head=insert;
        s++;
    }
    void pop(){
        if(head==nullptr)
        {
            cout<<"Stack is Empty";
            return;
        }
        head=head->next;
        s--;
    }
    int top(){
        if(head==nullptr)
        {
            cout<<"Stack is Empty";
            return -1;
        }
        return head->val;
    }
    int size()
    {
        if(head==nullptr)
        {
            cout<<"Stack is Empty";
            return -1;
        }
        return s;
    }
    void display(){
        if(head==nullptr)
        {
            cout<<"Stack is Empty";
            return;
        }
        Node* temp =head;
        while(temp!=nullptr)
        {
            cout<<temp->val<<" ";
            temp=temp->next;
        }

    }
};
int main()
{
    stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
     cout<<st.size()<<endl;
    cout<<st.top()<<endl;
    st.display();
    cout<<endl;
    st.pop();
    st.display();
}