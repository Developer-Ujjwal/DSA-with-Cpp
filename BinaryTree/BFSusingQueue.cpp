#include<iostream>
#include<queue>
using namespace std;
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int data) : val(data), left(nullptr), right(nullptr) {}
};
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
    Node *a = new Node(1);
    Node *b = new Node(2);
    Node *c = new Node(3);
    Node *d = new Node(4);
    Node *e = new Node(5);
    Node *f = new Node(6);
    Node *g = new Node(7);
    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;
    traverse(a);
}