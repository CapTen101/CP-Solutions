#include <bits/stdc++.h>
using namespace std;

void toposort(vector<pair<int, int>> *adj, stack<int> &s, vector<bool> &vis, int curr)
{
    vis[curr] = true;
    for (auto i : adj[curr])
    {
        if (!vis[i.first])
            toposort(adj, s, vis, i.first);
    }

    s.push(curr);
}

vector<int> shortestPath(vector<pair<int, int>> *adj, int n, int src)
{
    vector<bool> vis(n, false);
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
            toposort(adj, s, vis, i);
    }

    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    while (s.size())
    {
        int node = s.top();
        if (dist[node] != INT_MAX)
        {
            for (auto i : adj[node])
            {
                if (dist[node] + i.second < dist[i.first])
                    dist[i.first] = dist[node] + i.second;
            }
        }
    }

    // those elements who dist[i] is still INT_MAX, the are unreachable
    // rest have some value in their distances;
    return dist;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n];

    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
    }

    shortestPath(adj, n, 0);
}