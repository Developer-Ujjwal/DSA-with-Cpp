vector<vector<int>> dp;
int helper(int c,int wt[],int val[], int i, int w, int n)
{
    if(i==n) return 0;
    if(dp[i][w] != -1) return dp[i][w];
    if(w+wt[i]>c) return dp[i][w]=helper(c,wt,val,i+1,w,n);
    int take=val[i]+helper(c,wt ,val, i+1,w+wt[i],n);
    int leave=helper(c,wt,val,i+1,w,n);
    return dp[i][w]=max(take,leave);

}
int knapSack(int c,int wt[],int val[],int n)
{
    dp.resize(n,vector<int>(c+1,-1));
    return helper(c,wt,val,0,0,n);
}