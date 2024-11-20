#include<iostream>
#include<list>
#include<vector>
using namespace std;
int n;
vector<list<int>> graph;

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
    display();
}