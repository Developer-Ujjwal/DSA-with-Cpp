  #include<iostream>
  #include<vector>
    using namespace std;
     int fib(int n, vector<int>& ans) {
        if (n <= 1) return n;
        if(ans[n]!=-1) return ans[n];
        ans[n]=fib(n - 1,ans) + fib(n - 2,ans);
        return ans[n];
    }
    int main()
    {
        int n=3;
        vector<int> ans(n+1,-1);
        cout<<fib(n,ans);
    }