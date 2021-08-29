#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(vector<int> *adj, int V, int src)
{
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;
    queue<int> q;
    q.push(src);
    while (q.size())
    {
        int node = q.front();
        q.pop();
        for (int i : adj[node])
        {
            if (dist[node] + 1 < dist[i])
            {
                dist[i] = dist[node] + 1;
                q.push(i);
            }
        }
    }

    return dist;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}