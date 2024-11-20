#include<iostream>
#include<list>
#include<vector>
#include<unordered_set>
using namespace std;
int n;
vector<list<int>> graph;
vector<vector<int>> Paths;
unordered_set<int> visited;
void add_edge(int src,int dest,bool bidirec){
    graph[src].push_back(dest);
    if(bidirec) graph[dest].push_back(src);
}
void display()
{
    for(int i=0;i<n;i++)
    {
        cout<<i<<"->";
        for(auto v:graph[i])
        {
            cout<<v<<",";
        }
        cout<<endl;
    }
}
void allPath(int src,int dest,vector<int> path)
{
    if(src==dest) 
    {
        path.push_back(src);
        Paths.push_back(path);
        path.pop_back();
        return;
    }
    visited.insert(src);
    path.push_back(src);
    for(int x: graph[src])
    {
        if(!visited.count(x)) allPath(x,dest,path);
    }
    path.pop_back();
    visited.erase(src);
}

int main()
{
    
    cin>>n;
    graph.resize(n,list<int> ());

    int e;
    cin>>e;
    while(e--)
    {
        int src,dest;
        cin>>src>>dest;
        add_edge(src,dest,true);
    }
   
    allPath(2,0,vector<int> ());
    for(int i=0;i<Paths.size();i++)
    {
        for(int j=0;j<Paths[i].size();j++)
        {
            cout<<Paths[i][j]<<" ";
        }
        cout<<endl;
    }
   
}