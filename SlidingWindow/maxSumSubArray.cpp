#include<iostream>
#include<vector>
using namespace std;
long maximumSumSubarray(int K, vector<int> Arr, int N) {
    long sum = 0;
    int i = 0;
    while (i < K) {
        sum += Arr[i++];
    }
    long ans = sum;
    while (i < N) {
        sum -= Arr[i - K];
        sum += Arr[i];
        ans = max(ans, sum);
        i++;
    }
    return ans;
}
int main()
{
    vector<int> Arr = { 1, 4, 2, 10, 23, 3, 1, 0, 20 };
    int N = Arr.size();
    int K = 4;
    cout << maximumSumSubarray(K, Arr, N);
    return 0;

}