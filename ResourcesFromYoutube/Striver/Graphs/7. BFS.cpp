#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int n, vector<int> adj[])
    {
        queue<int> q;
        bool vis[n + 1];
        memset(vis, false, sizeof(vis));
        q.push(0);
        vector<int> bfs_arr;

        while (q.size())
        {
            int s = q.front();
            bfs_arr.push_back(s);
            q.pop();
            vis[s] = true;
            for (int i = 0; i < adj[s].size(); i++)
            {
                if (!vis[adj[s][i]])
                {
                    q.push(adj[s][i]);
                    vis[adj[s][i]] = true;
                }
            }
        }

        return bfs_arr;
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
        }
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}