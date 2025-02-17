#include <iostream>
#include <stack>
using namespace std;
int main()
{
    int arr[] = {100, 80, 60, 81, 70, 60, 75, 85};
    int n = sizeof(arr) / sizeof(arr[0]);
    stack<int> st;
    int ans[n];

    st.push(0);
    ans[0] = -1;
    for (int i = 1; i < n; i++)
    {
        while (!st.empty() && arr[i] > arr[st.top()]) st.pop();
        ans[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }

    for (int i = 0; i < n; i++)
    {
        ans[i]=i-ans[i];
        cout << ans[i] << " ";
    }
    return 0;
}