#include <iostream>
#include <queue>
using namespace std;
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int data) : val(data), left(nullptr), right(nullptr) {}
};
Node* convertedroot(int *arr,int n)
{
    int i=1;
    int j=2;
    queue<Node*> q;
    Node* r=new Node(arr[0]);
    q.push(r);
    while(q.front()&&i<n)
    {
        Node* temp=q.front();
        q.pop();
         Node* l=new Node(arr[i]);
       Node* r=new Node(arr[j]);
        temp->left=l;
        temp->right=r;
        q.push(l);
        q.push(r);
        i+=2;
        j+=2;

    }
    return r;
}
void traverse(Node* root)
{ 
        queue<Node*> q;
        q.push(root);
        while(q.front())
        {
            Node* temp=q.front();
            q.pop();
            cout<<temp->val<<" ";
            if(temp->left!=nullptr) q.push(temp->left);
            if(temp->right!=nullptr) q.push(temp->right);
        }
}
int main()
{
    int arr[]={1,2,3,4,5,6,7};
    int n=sizeof(arr)/sizeof(arr[0]);
    Node* root=convertedroot(arr,n);
    traverse(root);

}
/*
    int i = 1;
    int j = 2;
    queue<Node *> q;
    Node *r = new Node(arr[0]);
    q.push(r);
    while (q.front() && i < n)
    {
        Node *temp = q.front();
        q.pop();
        if (arr[i] != INT_MIN)
        {
            Node *l = new Node(arr[i]);
            q.push(l);
            temp->left = l;
        }
        else
        {
            Node *l = nullptr;
            temp->left = l;
        }
        if (j!=n && arr[j] != INT_MIN)
        {
            Node *r = new Node(arr[j]);
            q.push(r);
            temp->right = r;
        }
        else
        {
            Node *r = nullptr;
            temp->right = r;
        }

        i += 2;
        j += 2;
    }
    return r;
*/