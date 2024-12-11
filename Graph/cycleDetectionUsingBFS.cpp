#include <bits/stdc++.h>
using namespace std;
int n;
vector<list<int>> graph;

void add_edge(int src, int dest, bool bidirec)
{
    graph[src].push_back(dest);
    if (bidirec)
        graph[dest].push_back(src);
}
bool bfs(int src, vector<int>& parent, unordered_set<int> &vis)
{
    queue<int> qu;
    qu.push(src);
    vis.insert(src);
   while(!qu.empty())
   {
    int node=qu.front();
    qu.pop();
    for(auto neighbour:graph[node])
    {
        if( vis.count(neighbour)&& parent[node]!=neighbour)      //.... curr node ka parent neighbour nhi hai
        {
            //cycle detected
            return true;
        }
        if(!vis.count(neighbour))
        {
            qu.push(neighbour);
            vis.insert(neighbour);
            parent[neighbour]=node;
        }
    }
   }
    return false;
}
bool hasCycle()
{
    unordered_set<int> vis;
    vector<int> parent (n,-1);
    bool result = false;
    for (int i = 0; i < n; i++)
    {
        if (!vis.count(i))
        {
            parent[i]=i;
            result = bfs(i, parent, vis);

            if (result)
                return true;
        }
    }
    return result;
}

int main()
{

    cin >> n;
    graph.resize(n, list<int>());
    int e;
    cin >> e;
    while (e--)
    {
        int src, dest;
        cin >> src >> dest;
        add_edge(src, dest, true);
    }
    cout << hasCycle() << endl;
}