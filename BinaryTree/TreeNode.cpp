#include <iostream>
using namespace std;
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int data) : val(data), left(nullptr), right(nullptr) {}
};
 void display(Node *root)
{
    if(root==nullptr) return;
    cout<<root->val<<" ";
    display(root->left);
    display(root->right);
}
int sum(Node* root)
{
    if(root==nullptr) return 0;
    return root->val+sum(root->left)+sum(root->right);
}
int size(Node* root)
{
    if(root==nullptr) return 0;
    return 1+size(root->left)+size(root->right);
}
int product(Node* root)
{
    if(root==nullptr) return 1;
    return root->val*product(root->left)*product(root->right);
}
int maximum(Node* root)
{
    if(root==nullptr) return INT_MIN;
    return max(root->val,max(maximum(root->left),maximum(root->right)));
}
int Level(Node* root)
{
    if(root==nullptr) return 0;
    return 1+max(Level(root->left),Level(root->right));
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
    Node *h = new Node(1);
    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;
    d->right=h;
    display(a);
    cout<<endl<<sum(a)<<endl;
    cout<<size(a)<<endl;
    cout<<product(a)<<endl;
    cout<<maximum(a)<<endl;
    cout<<Level(a)<<endl;

}