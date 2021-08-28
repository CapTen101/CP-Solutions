#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isCyclic(int V, vector<int> adj[])
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

        int count = 0;
        while (nodes.size())
        {
            int node = nodes.front();
            nodes.pop();
            count++;
            for (int i : adj[node])
            {
                inDegree[i]--;
                if (inDegree[i] == 0)
                    nodes.push(i);
            }
        }

        // if count has V elements, then toposort was successful hence no cycle
        // else, there's a cycle
        return (count == V ? false : true);
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