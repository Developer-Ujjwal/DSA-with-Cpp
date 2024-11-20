#include <iostream>
#include <stack>
using namespace std;
int priority(char ch)
{
    if (ch == '+' || ch == '-')
        return 1;
    else
        return 2;
}
int solve(int val1, int val2, char ch)
{
    if (ch == '+')
        return val1 + val2;
    else if (ch == '-')
        return val1 - val2;
    else if (ch == '*')
        return val1 * val2;
    else
        return val1 / val2;
}

int main()
{
    string s = "2+6*4/8-3";
    stack<int> val;
    stack<char> op;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 48 && s[i] <= 57) // digit
            val.push(s[i] - 48);
        else // s[i]-> + - * /
        {
            if (op.size() == 0)
                op.push(s[i]);
            else if (priority(op.top()) < priority(s[i]))
                op.push(s[i]);
            else // work
            {
                while (op.size() && priority(op.top()) >= priority(s[i]))
                {
                    char ch = op.top();
                    op.pop();
                    int val2 = val.top();
                    val.pop();
                    int val1 = val.top();
                    val.pop();
                    int ans = solve(val1, val2, ch);                //val1 op val2
                     val.push(ans);
                }
                op.push(s[i]);
            }
        }
    }
    // the operator stack can have values
    // so make it empty
    while (op.size() != 0)
    {
        char ch = op.top();
        op.pop();
        int val2 = val.top();
        val.pop();
        int val1 = val.top();
        val.pop();
        int ans = solve(val1, val2, ch);
        val.push(ans);
    }
    cout<<val.top();
}
