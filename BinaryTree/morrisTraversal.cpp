//inorder 
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
void morrisTraversal(Node* root)
{
Node* curr=root;
while(curr!=nullptr)
{
    if(curr->left!=nullptr)
    {
       Node* pred=curr->left;
        while(pred->right!=nullptr && pred->right!=curr)
        {
            pred=pred->right;
        }
        if(pred->right==nullptr)
        {
            pred->right=curr;
            curr=curr->left;
        }
        if(pred->right==curr)
        {
            cout<<curr->val<<" ";
            pred->right=nullptr;
            curr=curr->right;
        }
    }
    else 
    {
         cout<<curr->val<<" ";
        curr=curr->right;

    }
}
}
int main()
{
 Node *a = new Node(10);
    Node *b = new Node(5);
    Node *c = new Node(15);
    Node *d = new Node(3);
    Node *e = new Node(8);
    Node *f = new Node(6);
    Node *g = new Node(20);
    Node *h = new Node(18);
    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->right = g;
   e->left=f;
   g->left=h;

    morrisTraversal(a);
   
}