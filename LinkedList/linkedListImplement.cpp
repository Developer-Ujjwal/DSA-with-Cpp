#include <iostream>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node(int value) : val(value), next(NULL) {}
};
class linkedlist
{
public:
    Node *head;
    int size;
    linkedlist()
    {
        head = nullptr;
        size = 0;
    }
    void insertAtEnd(int data)
    {
        Node *temp = new Node(data);
        if (size == 0)
        {
            head = temp;
        }
        else
        {
            Node *ptr = head;
            while (ptr->next != nullptr)
            {
                ptr = ptr->next;
            }
            ptr->next = temp;
        }
        size++;
    }
    void insertAtStart(int data)
    {
        Node *temp = new Node(data);
        if (size == 0)
        {
            head = temp;
        }
        else
        {
            temp->next = head;
            head = temp;
        }
        size++;
    }
    void insertAtIndex(int idx, int data)
    {
        Node *temp = head;
        Node *insert = new Node(data);
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
            int mdx = 0;
            while (mdx < idx - 1)
            {
                temp = temp->next;
                mdx++;
            }
            insert->next = temp->next;
            temp->next = insert;
        }
        size++;
    }
    int getAtIndex(int idx)
    {
        if (idx >= size || idx < 0)
        {
            cout << "Index out of bound";
            return -1;
        }
        else
        {
            Node *temp = head;
            int mdx = 0;
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
        {
            cout << "ll not present";
        }
        else if (size > 1)
        {
            head = head->next;
        }
        else
            head = nullptr;
        size--;
    }
    void deleteAtEnd()
    {
        if (size <= 0)
        {
            cout << "ll not present";
        }
        else if (size > 1)
        {
            Node *temp = head;
            int mdx = 0;
            while (mdx != size - 2)
            {
                temp = temp->next;
                mdx++;
            }
            temp->next = nullptr;
        }
        else
            head = nullptr;
        size--;
    }
    void deleteAtIndex(int idx)
    {
        if (idx >= size || idx < 0)
        {
            cout << "Index out of bound";
            return;
        }
        else if (idx > 1)
        {
            int mdx = 0;
            Node *temp = head;
            while (mdx != idx - 1)
            {
                temp = temp->next;
                mdx++;
            }
            temp->next = nullptr;
        }
        else
            head = nullptr;
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
    }
};

int main()
{
    linkedlist myList;
    myList.insertAtEnd(10);
    myList.insertAtEnd(20);
    myList.insertAtStart(5);
    myList.insertAtIndex(1, 15);

    cout << "Values in the list: " << endl;
    myList.display();

    cout << "\nValue at index 2: " << myList.getAtIndex(2) << endl;

    myList.deleteAtEnd();
    cout << "After deleting the last element: " << endl;
    myList.display();

    return 0;
}