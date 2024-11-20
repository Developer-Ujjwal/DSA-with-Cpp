#include <bits/stdc++.h>
using namespace std;

int kthSmallest(vector<vector<int>>& mat, int k){
    priority_queue<int, vector<int>, greater<int>> pq;
    int n=mat.size();
    int m=mat[0].size();
    int ans=0;
    for(int i=0;i<n;i++){
        pq.push(mat[i][0]);
    }
    for(int i=0;i<k-1;i++){
        ans=pq.top();
        pq.pop();
        int row=pq.size();
        int col=0;
        while(row>=0 && col<m){
            if(mat[row][col]<ans){
                col++;
            }
            else{
                row--;
            }
        }
        if(col==m){
            row--;
        }
        if(row!=-1){
            pq.push(mat[row][col]);
        }
    }
    return ans;
}

int main(){
    vector<vector<int>> mat={{10,20,30,40},{15,25,35,45},{27,29,37,48},{32,33,39,50}};
    int k=7;
    cout<<kthSmallest(mat,k);
}
