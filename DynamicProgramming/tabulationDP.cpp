    #include<iostream>
    using namespace std;
    
    int fib(int n) {
        if(n<=1) return n;
        int arr[n+1];
        arr[0]=0;
        arr[1]=1;
        for(int i=2;i<=n;i++)
        {
            arr[i]=arr[i-1]+arr[i-2];

        }
        return arr[n];
    }
    int main()
    {
        int n=3;
        cout<<fib(n);
    }