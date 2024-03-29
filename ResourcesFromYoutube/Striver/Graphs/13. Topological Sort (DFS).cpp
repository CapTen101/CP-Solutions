#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //Function to return list containing vertices in Topological order.
    void helper(vector<int> *adj, vector<bool> &vis, stack<int> &nodes, int curr)
    {
        vis[curr] = true;
        for (int i : adj[curr])
        {
            if (!vis[i])
            {
                helper(adj, vis, nodes, i);
            }
        }

        nodes.push(curr); // push in stack
    }

    vector<int> topoSort(int V, vector<int> adj[])
    {
        vector<bool> vis(V, false);
        stack<int> nodes;
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                helper(adj, vis, nodes, i);
            }
        }

        // the stack contains the element in ONE of the many topo sort orders
        vector<int> toposort;
        while (nodes.size())
        {
            toposort.push_back(nodes.top());
            nodes.pop();
        }

        return toposort;
    }
};

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector<int> &res, vector<int> adj[])
{

    if (V != res.size())
        return 0;

    vector<int> map(V, -1);
    for (int i = 0; i < V; i++)
    {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++)
    {
        for (int v : adj[i])
        {
            if (map[i] > map[v])
                return 0;
        }
    }
    return 1;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++)
        {
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }

    return 0;
}