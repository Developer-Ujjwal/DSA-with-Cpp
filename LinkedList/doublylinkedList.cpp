#include <iostream>
using namespace std;
class Node
{
public:
    int val;
    Node *prev;
    Node *next;
    Node(int value)
    {
        val = value;
        prev = nullptr;
        next = nullptr;
    }
};
class doublylinkedList
{
public:
    Node *head;
    Node *tail;
    int size;
    doublylinkedList()
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    void insertAtStart(int data)
    {
        Node *temp = new Node(data);
        if (head == nullptr)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
        size++;
    }
    void insertAtEnd(int data)
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
            temp->prev = tail;
            tail = temp;
        }
        size++;
    }
    void insertAtIndex(int idx, int data)
    {

        if (idx > size || idx < 0)
        {
            cout << "Index out of bound";
            return;
        }
        else if (idx == 0)
        {
            insertAtStart(data);
            return;
        }
        else if (idx == size)
        {
            insertAtEnd(data);
            return;
        }
        else
        {
            Node *insert = new Node(data);
            Node *temp = head;
            int mdx = 0;
            while (mdx != idx - 1)
            {
                temp = temp->next;
                mdx++;
            }
            insert->next = temp->next;
            temp->next = insert;
            insert->prev = temp;
            insert->next->prev = insert;
        }
        size++;
    }
    int getAtIndex(int idx)
    {
        if (idx < 0 || idx >= size)
        {
            cout << "Index out of bound";
            return -1;
        }
        else
        {
            int mdx = 0;
            Node *temp = head;
            while (mdx != idx)
            {
                temp = temp->next;
                mdx++;
            }
            return temp->val;
        }
    }
    void deleteAtHead()
    {
        if (size <= 0)
            cout << "Nothing to delete";
        else if (size > 1)
        {
            head->next->prev = nullptr;
            head = head->next;
        }
        else
        {
            head = nullptr;
            tail = nullptr;
        }
        size--;
    }
    void deleteAtEnd()
    {
        if (size <= 0)
            cout << "Nothing to delete";
        else if (size > 1)
        {
            tail->prev->next = nullptr;
            tail = tail->prev;
        }
        else
        {
            head = nullptr;
            tail = nullptr;
        }
        size--;
    }
    void deleteAtIndex(int idx)
    {
        if (idx < 0 || idx >= size)
        {
            cout << "Index out of bound";
            return;
        }
        else if (idx == 0)
        {
            deleteAtHead();
            return;
        }
        else if (idx == size - 1)
        {
            deleteAtEnd();
            return;
        }
        else
        {
            int mdx = 0;
            Node *temp = head;
            while (mdx != idx)
            {
                temp = temp->next;
                mdx++;
            }
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
        }
        size--;
    }
    void display()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
        delete temp;
        cout<<endl;
    }
};
int main() {
    doublylinkedList dll;
    dll.insertAtStart(1);
    dll.insertAtEnd(2);
    dll.insertAtEnd(3);
    dll.insertAtIndex(1, 4);
    dll.display(); // 1 4 2 3
    dll.deleteAtHead();
    dll.display(); // 4 2 3
    dll.deleteAtEnd();
    dll.display(); // 4 2
    dll.deleteAtIndex(1);
    dll.display(); // 4
    return 0;
}