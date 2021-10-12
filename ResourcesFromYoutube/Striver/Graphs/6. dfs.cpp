#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //Function to return a list containing the DFS traversal of the graph.
    void dfs(int s, vector<int> adj[], vector<int> &dfs_arr, bool *vis)
    {
        dfs_arr.push_back(s);
        vis[s] = true;
        for (int i = 0; i < adj[s].size(); i++)
        {
            if (!vis[adj[s][i]])
                dfs(adj[s][i], adj, dfs_arr, vis);
        }
    }
    vector<int> dfsOfGraph(int n, vector<int> adj[])
    {
        vector<int> dfs_arr;
        bool vis[n + 1];
        memset(vis, false, sizeof(vis));
        dfs(0, adj, dfs_arr, vis);

        return dfs_arr;
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
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
} // } Driver Code Ends