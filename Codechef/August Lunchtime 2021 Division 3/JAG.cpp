#include <bits/stdc++.h>
using namespace std;

#define my_sizeof(type) ((char *)(&type + 1) - (char *)(&type))
#define FOR(i, start, end) for (int i = start; i < end; i++)
#define ll long long int
#define ull unsigned long long int
#define ul unsigned long int
#define get cin >>
#define print cout <<
#define inarr(s, n, arr)        \
    for (int i = s; i < n; i++) \
        cin >> arr[i];
#define outarr(s, n, arr)       \
    for (int i = s; i < n; i++) \
        cout << arr[i];
#define start \
    int t;    \
    cin >> t; \
    while (t--)

void BFS(int i, vector<int> adj, vector<bool> &visit, int &count)
{
    queue<int> q;
    q.push(i);
    int node;
    while (!q.empty())
    {
        node = q.front();
        q.pop();
        if (!visit[node])
        {
            for (auto it : adj[node])
            {
                q.push(it);
            }
            visit[node] = true;
        }
    }
    count++;
}

int ConnectedComponents(vector<int> adj[], int V)
{
    vector<bool> visit(V, false);
    int count = 0;
    for (int i = 0; i <= V; i++)
    {
        if (!visit[i])
        {
            BFS(i, adj, visit, count);
        }
    }
    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    start
    {
        int n;
        cin >> n;

        // Mark all the vertices as not visited
        vector<bool> visited(n + 1, false);
        vector<int> wt(n + 1);

        for (int i = 1; i <= n; i++)
        {
            cin >> wt[i];
        }

        // To store the number of connected components
        int count = 0;
        for (int v = 1; v <= n; v++)
            visited[v] = false;

        return count;
    }
}