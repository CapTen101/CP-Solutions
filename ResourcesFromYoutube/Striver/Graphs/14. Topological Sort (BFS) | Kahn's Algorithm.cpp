#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> topoSort(int V, vector<int> adj[])
    {
        queue<int> nodes;
        vector<int> inDegree(V, 0);
        // get all inDegree for all nodes
        for (int i = 0; i < V; i++)
        {
            for (int j : adj[i])
                inDegree[j]++;
        }

        // if inDegree is 0, then push into queue
        for (int i = 0; i < V; i++)
        {
            if (inDegree[i] == 0)
                nodes.push(i);
        }

        // subtract inDegree by 1 everytime you visit a node, if inDegree becomes 0 then again push
        vector<int> toposort;
        while (nodes.size())
        {
            int node = nodes.front();
            nodes.pop();
            toposort.push_back(node);
            for (int i : adj[node])
            {
                inDegree[i]--;
                if (inDegree[i] == 0)
                    nodes.push(i);
            }
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