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
void level(Node* root,int curr,int lvl)
{
    if(root==nullptr) return;
    if(curr==lvl)
    {
        cout<<root->val<<" ";
        return;
    }
    level(root->left,curr+1,lvl);
    level(root->right,curr+1,lvl);

}
void preorder(Node* root)
{
    if(root==nullptr) return;
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(Node* root)
{
    if(root==nullptr) return;
 
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}
void postorder(Node* root)
{
    if(root==nullptr) return;
    preorder(root->left);
    preorder(root->right);
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
    level(a,1,1);
    cout<<endl;
    level(a,1,2);
    cout<<endl;
    level(a,1,3);
    cout<<endl;
    preorder(a);
    cout<<endl;
    inorder(a);
    cout<<endl;
    postorder(a);
    cout<<endl;
}