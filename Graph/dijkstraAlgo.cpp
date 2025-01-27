#include<bits/stdc++.h>
#define pp pair<int,int>
using namespace std;
vector<list<pp>> gr;
void add_edge(int u,int v, int wt,bool bidir=true)
{
    gr[u].push_back({v,wt});
    if(bidir) gr[v].push_back({u,wt});
}

int dijkstra(int src,int dest,int n)
{
    unordered_map<int,int> table;  //contain distance from source to node
    vector<int> via(n+1,0);            //for path tracing
    priority_queue<pp,vector<pp>,greater<pp>> pq;   // contain smallest wt to be picked
    unordered_set<int> vis;
    for(int i=0;i<=n;i++) table[i]=INT_MAX;
    table[src]=0;
    via[src]=src;
    int edgeCount=0;
    pq.push({0,src});
    while(!pq.empty())
    {
        pp curr=pq.top();

        if(vis.count(curr.second))
        {
            pq.pop();
            continue;
        }
        else{
            pq.pop();
            vis.insert(curr.second);
            for(auto neighbour: gr[curr.second])
            {
                if(!vis.count(neighbour.first) &&table[neighbour.first]>table[curr.second]+neighbour.second)
                {
                    table[neighbour.first]=table[curr.second]+neighbour.second;
                    via[neighbour.first]=curr.second;
                    pq.push({table[curr.second]+neighbour.second,neighbour.first});
                }
            }
        }
    }
    for(int i=0;i<=n;i++)
    {
        cout<<i<<" "<<table[i]<<endl;

    }
    return table[dest];

    
}
int main()
{
    int n,m;
    cin>>n>>m;
    gr.resize(n+1,list<pp>());
    while(m--){
        int u,v,wt;
        cin>>u>>v>>wt;
        add_edge(u,v,wt);
    }
    int src,dest;
    cin>>src>>dest;
    cout<<dijkstra(src,dest,n);

}