//mst-> Minimum spanning tree -> tree/subgraph having all vertex but m no. of edges able to keep it connected with minimum wt possible 

#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int find(int x,vector<int>&parent)
{
    return parent[x]=(parent[x]==x)?x:find(parent[x],parent);
}
void Union(vector<int>&size, vector<int>&parent, int src, int dist) 
{
    int X=find(src,parent);
    int Y=find(dist,parent);
    if(X==Y) return;
    if(size[X]>=size[Y])
    {
        parent[Y]=X;
        size[X]++;
    }
    else{
        parent[X]=Y;
        parent[Y]++;
    }
}
struct Edge{
    int src;
    int dest;
    int wt;
};
bool cmp(Edge e1,Edge e2){
    return e1.wt<e2.wt;
}
ll kruskals(vector<Edge>& input, int v, int e)               //sort on the basis of wt --> iterate through sorted edges and remove edge if cycle detected
{
    sort(input.begin(),input.end(),cmp);
    vector<int> parent(v+1);
    vector<int> size(v+1,1);
    for(int i=0;i<=v;i++) parent[i]=i;
    int edgeCount=0;   //v-1
    int i=0;
    ll ans=0;
    while(edgeCount<v-1 && i< input.size())
    {
        Edge curr=input[i];                 //bcz input is sorted so we will get min wt edge
        int srcPar=find(curr.src,parent);
        int destPar=find(curr.dest,parent);
        if(srcPar!=destPar)
        {
            //include edge as it will not make cycle
            Union(size,parent,srcPar,destPar);
            ans+=curr.wt;
            edgeCount++;
        } 
        i++;
        
    }
    return ans;
}
int main()
{
     int v,e;
     cin >>v>>e;
    vector<Edge> input(e);
    for(int i=0;i<e;i++)
    {
        cin>>input[i].src>>input[i].dest>>input[i].wt;
    }
    cout<<kruskals(input,v,e)<<endl;
    return 0;
   




}