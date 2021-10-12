#include <bits/stdc++.h>
using namespace std;

bool bfs(bool *vis, vector<int> *adj, int start)
{
    vis[start] = true;
    queue<pair<int, int>> q;
    q.push({start, -1});

    while(q.size())
    {
        pair<int, int> p = q.front();
        int node = p.first;
        int parentNode = p.second;
        q.pop();
        for(int i : adj[node])
        {
            if(!vis[i])
            {
                vis[i] = true;
                q.push({i, node});
            }
            else if(i!=parentNode)
                return true;
        }
    }

    return false;
}

int solve(int n, vector<vector<int> > &b) 
{
    int r = b.size();
    bool vis[n+1];
    memset(vis, false, sizeof(vis));

    vector<int> adj[n+1];
    for(int i=0; i<r; i++)
    {
        adj[b[i][0]].push_back(b[i][1]);
        adj[b[i][1]].push_back(b[i][0]);
    }

    for(int i=1; i<=n; i++)
    {
        if(!vis[i])
            if(bfs(vis, adj, i))
                return true;
    }

    return false;
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}