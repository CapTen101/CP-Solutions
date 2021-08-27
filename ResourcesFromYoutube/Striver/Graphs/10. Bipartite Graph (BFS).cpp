#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool helper(vector<int> *adj, vector<int> &color, int curr)
    {
        queue<int> q;
        q.push(curr);
        color[curr] = 0;

        while (q.size())
        {
            int node = q.front();
            q.pop();

            for (int i : adj[node])
            {
                if (color[i] == -1)
                {
                    color[i] = (color[node] == 0 ? 1 : 0);
                    q.push(i);
                }
                else if (color[i] == color[node])
                    return false;
            }
        }

        return true;
    }
    bool isBipartite(int n, vector<int> adj[])
    {
        vector<int> color(n, -1);
        for (int i = 0; i < n; i++)
        {
            if (color[i] == -1)
            {
                bool flag = helper(adj, color, i);
                if (!flag)
                    return false;
            }
        }

        return true;
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
        bool ans = obj.isBipartite(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
