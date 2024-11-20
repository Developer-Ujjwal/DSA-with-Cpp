#include <iostream>
#include <vector>
using namespace std;
class Queue
{
public:
    vector<int> arr;
    int f;
    int b;
    int s;
    int c;
    Queue(int k)
    {
        f = 0;
        b = 0;
        s = 0;
        vector<int> v(k);
        arr = v;
        c = k;
    }
    void push(int val)
    {
        if (s == c)
        {
            cout << "Queue is Full"<<endl;
            return;
        }
        arr[b] = val;
        b++;
        if (b == c)
            b = 0; // imp
        s++;
    }
    void pop()
    {
        if (s == 0)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        f++;
        if (f == c)
            f = 0; // imp
        s--;
    }
    int front()
    {
        if (s == 0)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[f];
    }
    int back()
    {
        if (s == 0)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        if (b == 0)
            return arr[c - 1]; // imp
        return arr[b - 1];
    }
    int size()
    {
        return s;
    }
    bool empty()
    {
        if (s == 0)
            return true;
        else
            return false;
    }
    void display()
    {
        if (b <= f)
        {
            for (int i = f; i < c; i++)
            {
                cout << arr[i] << " ";
            }
            for(int i=0;i<b;i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        else
        {
        for (int i = f; i < b; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
        }
    }
};
int main()
{
    Queue q(5);
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.display();
    q.push(50);
    q.push(60);
    q.display();
    q.pop();
    q.display();
}