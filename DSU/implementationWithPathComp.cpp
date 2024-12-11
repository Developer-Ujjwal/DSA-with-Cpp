#include<iostream>
#include<vector>
using namespace std;
int find(vector<int>& parent,int x){
    return parent[x]= (parent[x]==x)?x:find(parent,parent[x]); //this method returns which group x belongs to
}

void Union(vector<int> &parent,vector<int> &rank,int x,int y){
    x=find(parent,x);
    y=find(parent,y);
    if(rank[x]>rank[y]){
        parent[y]=x;
        rank[x]++;
    }
    else {
        parent[x]=y;
        rank[y]++;
    }
}
int main(){
    int n,m;
     cin>>n>>m;
    //n->elements m->no. of queries
    vector<int> parent(n+1);
    vector<int> rank(n+1,0);
    for(int i=0;i<=n;i++) parent[i]=i;
   
    while(m--)
    {
        string str;
        cin>>str;
        if(str=="union"){
            int x,y;
            cin>>x>>y;
            Union(parent,rank,x,y);
        }
        else if(str=="find"){
            int x;
            cin>>x;
            cout<<find(parent,x)<<endl;
        }
    }
    return 0;
}