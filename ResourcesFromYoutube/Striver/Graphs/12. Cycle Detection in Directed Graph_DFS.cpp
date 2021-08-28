#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to detect cycle in a directed graph.
    bool helper(vector<int> *adj, vector<bool> &vis, vector<bool> &dfs_vis, int curr)
    {
        vis[curr] = true;
        dfs_vis[curr] = true;

        for (int i : adj[curr])
        {
            if (!vis[i])
            {
                bool flag = helper(adj, vis, dfs_vis, i);
                if (flag)
                    return true;
            }
            else if (dfs_vis[i])
                return true;
        }

        dfs_vis[curr] = false;
        return false;
    }

    bool isCyclic(int n, vector<int> adj[])
    {
        vector<bool> vis(n, false);
        vector<bool> dfs_vis(n, false);
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                bool flag = helper(adj, vis, dfs_vis, i);
                if (flag)
                    return true;
            }
        }

        return false;
    }
};

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}