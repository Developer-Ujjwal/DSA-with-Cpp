#include <iostream>
#include <stack>
using namespace std;
bool IsbalancedBracket(string str)
{
    if(str.length()%2!=0) return false;
    stack<char> st;
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == '(')
        {
            st.push('(');
        }
        if (str[i] == ')')
        {
            if (st.top() == '(')
                st.pop();
            else return false;
        }
        i++;
    }
    if (st.size() == 0)
        return true;
    else
        return false;
}
int main()
{
    string str="()()()";
    cout<<IsbalancedBracket(str);
}