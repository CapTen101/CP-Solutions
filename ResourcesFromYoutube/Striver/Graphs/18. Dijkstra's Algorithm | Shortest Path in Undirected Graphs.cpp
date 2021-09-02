#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<int> dist(V, INT_MAX);
        dist[S] = 0;                                                                             // distance of source from source = 0
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap; // minHeap
        minHeap.push({0, S});

        while (minHeap.size())
        {
            int d = minHeap.top().first;
            int prev = minHeap.top().second;
            minHeap.pop();

            for (auto i : adj[prev])
            {
                int next = i[0];
                int nextDist = i[1];
                if (dist[prev] + nextDist < dist[next]) // if lesser distance found for 'next', update it
                {
                    dist[next] = dist[prev] + nextDist;
                    minHeap.push({dist[next], next});
                }
            }
        }

        return dist;
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
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E)
        {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin >> S;

        Solution obj;
        vector<int> res = obj.dijkstra(V, adj, S);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}