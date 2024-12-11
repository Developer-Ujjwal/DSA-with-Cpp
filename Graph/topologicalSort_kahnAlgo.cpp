#include <bits/stdc++.h>
using namespace std;

vector<list<int>> graph;
int v;
void add_edge(int x, int y, bool bidir = true)
{
    graph[x].push_back(y);
    if (bidir)
        graph[y].push_back(x);
}

void topoBFS()
{
    vector<int> indegree(v, 0);
    for (int i = 0; i < v; i++)
    {
        for (auto neighbour : graph[i])
        {
            indegree[neighbour]++;
        }
    }
    queue<int> qu;
    unordered_set<int> vis;
    for (int i = 0; i < v; i++)
    {
        if (indegree[i] == 0)
        {
            qu.push(i);
            vis.insert(i);
        }
    }
    while (not qu.empty())
    {
        int x = qu.front();
        cout << x << " ";
        qu.pop();
        for (auto neighbour : graph[x])
        {
            if (not vis.count(neighbour))
            {
                indegree[neighbour]--;
                if (indegree[neighbour] == 0)
                {
                    qu.push(neighbour);
                    vis.insert(neighbour);
                }
            }
        }
    }
}
int main()
{
    cin >> v;
    int e;
    cin >> e;
    graph.resize(v, list<int>());
    while (e--)
    {
        int x, y;
        cin >> x >> y;
        add_edge(x, y, false);
    }
    topoBFS();
    return 0;
}