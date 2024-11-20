#include <iostream>
#include <stack>
using namespace std;
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int data) : val(data), left(nullptr), right(nullptr) {}
};
void preorder(Node *root)
{
    stack<Node *> st;
    st.push(root);
    while (st.top())
    {
        Node *temp = st.top();
        st.pop();
        cout << temp->val << " ";
        Node *l;
        Node *r;
        if (temp->left != nullptr) l = (temp->left); 
        else l = nullptr;
        if (temp->right != nullptr) r = (temp->right);
        else r = nullptr;
        if (r != nullptr) st.push(r);
        if (l != nullptr) st.push(l);
    }
}
void postorder(Node *root)
{
    stack<Node *> st;
    st.push(root);
    while (st.top())
    {
        Node *temp = st.top();
        st.pop();
        cout << temp->val << " ";
        Node *l;
        Node *r;
        if (temp->left != nullptr) l = (temp->left);
        
        else  l = nullptr;
        if (temp->right != nullptr)  r = (temp->right);
        else r = nullptr;
        if (l != nullptr)  st.push(l);
        if (r != nullptr) st.push(r);
    }
}
void inorder(Node *root)
{
    stack<Node *> st;
    Node *node = root;
    while (1)
    {
        if (node != nullptr)
        {
            st.push(node);
            node = node->left;
        }
        else
        {
            if (st.empty())
            {
                break;
            }
            Node *temp = st.top();
            st.pop();
            cout << temp->val<<" ";
            node = temp->right;
        }
    }
    delete node;
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
    preorder(a);
    cout << endl;
    postorder(a); // jo aa rha uska reverse
    cout << endl;
    inorder(a);
}