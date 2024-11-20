#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
int n;
vector<unordered_map<int,int>> graph;

void add_edge(int src,int dest,int wt,bool bidirec){
    graph[src][dest]=wt;
    if(bidirec) graph[dest][src]=wt;
}
void display()
{
    for(int i=0;i<n;i++)
    {
        cout<<i<<"->";
        for(auto v:graph[i])
        {
            cout<<"("<<v.first<<","<<v.second<<"),";
        }
        cout<<endl;
    }
}

int main()
{
    
    cin>>n;
    graph.resize(n,unordered_map<int,int> ());
    int e;
    cin>>e;
    while(e--)
    {
        int src,dest,wt;
        cin>>src>>dest>>wt;
        add_edge(src,dest,wt,true);
    }
    display();
}