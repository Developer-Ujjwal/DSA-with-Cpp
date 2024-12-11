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
bool dfs(int src, int parent, unordered_set<int> &vis)
{
    vis.insert(src);
    for (auto neighbour : graph[src])
    {
        if (vis.count(neighbour) && neighbour != parent)
        {
            // cycle detected
            return true;
        }
        if (!vis.count(neighbour))
        {
            bool a = dfs(neighbour, src, vis);
            if (a)
                return true;
        }
    }
    return false;
}
bool hasCycle()
{
    unordered_set<int> vis;
    bool result = false;
    for (int i = 0; i < n; i++)
    {
        if (!vis.count(i))
        {
            result = dfs(i, -1, vis);
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