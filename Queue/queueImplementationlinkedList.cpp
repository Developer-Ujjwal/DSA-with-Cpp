#include <iostream>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node(int value)
    {
        val = value;
        next = nullptr;
    }
};
 class Queue
{
public:
    Node *head;
    Node *tail;
    int size;
    Queue()
    {
        head=tail=nullptr;
        size=0;
    }
    void push(int data)
    {
        Node *temp = new Node(data);
        if (size == 0)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
        size++;
    }
    void pop()
    {
        if(size==0) 
        {
            cout<<"Queue is Empty";
            return;
        }
        head=head->next;
        size--;
    }
    int front()
    {
        if(size==0) 
        {
            cout<<"Queue is Empty";
            return -1;
        }
        return head->val;
    }
    int back()
    {
        if(size==0) 
        {
            cout<<"Queue is Empty";
            return -1;
        }
        return tail->val;
    }
    void display()
    {
        Node* temp=head;
        while(temp!=nullptr)
        {
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    int length()
    {
        return size;
    }



};
int main()
{
    Queue q;
    cout<<q.length()<<endl;
     q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.display();
    q.push(50);
    q.push(60);
    cout<<q.front()<<endl;
    cout<<q.back()<<endl;
    q.display();
    q.pop();
    q.display();
}