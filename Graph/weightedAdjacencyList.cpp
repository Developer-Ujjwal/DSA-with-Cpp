#include<iostream>
#include<list>
#include<vector>
using namespace std;
int n;
vector<list<pair<int,int>>> graph;

void add_edge(int src,int dest,int weight,bool bidirec){
    graph[src].push_back({dest,weight});
    if(bidirec) graph[dest].push_back({src,weight});
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
    graph.resize(n,list<pair<int,int>> ());
    int e;
    cin>>e;
    while(e--)
    {
        int src,dest,weight;
        cin>>src>>dest>>weight;
        add_edge(src,dest,weight,true);
    }
    display();
}