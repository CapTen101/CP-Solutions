#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //Function to detect cycle in an undirected graph.

    bool helper(vector<int> *adj, bool *vis, int parentNode, int curr)
    {
        vis[curr] = true;
        for (int i : adj[curr])
        {
            if (!vis[i])
            {
                bool flag = helper(adj, vis, curr, i);
                if (flag)
                    return true;
            }
            else if (i != parentNode)
                return true;
        }

        return false;
    }

    bool isCycle(int n, vector<int> adj[])
    {
        bool vis[n + 1];
        memset(vis, false, sizeof(vis));
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                bool flag = helper(adj, vis, -1, i);
                if (flag)
                    return true;
            }
        }

        return false;
    }
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}