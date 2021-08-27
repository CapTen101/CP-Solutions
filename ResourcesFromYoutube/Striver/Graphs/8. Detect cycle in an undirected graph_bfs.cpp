#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //Function to detect cycle in an undirected graph.

    bool helper(vector<int> *adj, bool *vis, int curr)
    {
        queue<pair<int, int>> q;
        q.push({curr, -1}); // init parent node as -1
        vis[curr] = true;

        while (q.size())
        {
            int node = q.front().first;
            int parentNode = q.front().second;
            q.pop();

            for (int i = 0; i < adj[node].size(); i++)
            {
                if (!vis[adj[node][i]])
                {
                    vis[adj[node][i]] = true;
                    q.push({adj[node][i], node});
                }
                else if (adj[node][i] != parentNode)
                    return true;
            }
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
                bool flag = helper(adj, vis, i);
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