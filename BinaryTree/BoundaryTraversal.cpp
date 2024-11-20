#include<iostream>
using namespace std;
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int data) : val(data), left(nullptr), right(nullptr) {}
};
void leftBoundary(Node* root)
{
    if(root==nullptr) return;
    if(root->left==nullptr&&root->right==nullptr) return;
    cout<<root->val<<" ";
    leftBoundary(root->left);
    if(root->left==nullptr)leftBoundary(root->right);
}
void BottomBoundary(Node* root)
{
    if(root==nullptr) return;
    if(root->left==nullptr&&root->right==nullptr) cout<<root->val<<" ";
    BottomBoundary(root->left);
    BottomBoundary(root->right);
}
void rightBoundary(Node* root)
{
    if(root==nullptr) return;
    if(root->left==nullptr&&root->right==nullptr) return;
    rightBoundary(root->right);
    if(root->right==nullptr)rightBoundary(root->left);
     cout<<root->val<<" ";
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
    leftBoundary(a);
    BottomBoundary(a);
    rightBoundary(a->right);
}