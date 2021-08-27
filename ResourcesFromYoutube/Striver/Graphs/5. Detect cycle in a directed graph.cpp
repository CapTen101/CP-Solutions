#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //Function to detect cycle in a directed graph.
    bool helper(vector<int> *adj, bool *vis, int curr)
    {
        if (vis[curr])
            return true;

        vis[curr] = true;
        for (int i = 0; i < adj[curr].size(); i++)
        {
            bool flag = helper(adj, vis, adj[curr][i]);
            if (flag)
                return true;
        }

        return false;
    }
    bool isCyclic(int n, vector<int> adj[])
    {
        bool vis[n];
        memset(vis, false, sizeof(vis));

        for (int i = 0; i < n; i++)
        {
            vis[i] = true; // mark it true since we are going to the children of this node further
            for (int j = 0; j < adj[i].size(); j++)
            {
                bool flag = helper(adj, vis, adj[i][j]);
                if (flag)
                    return true;
            }
            vis[i] = false; // now again mark false since checking this node is over
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