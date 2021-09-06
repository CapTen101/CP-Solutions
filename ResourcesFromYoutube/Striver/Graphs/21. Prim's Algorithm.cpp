#include <bits/stdc++.h>
using namespace std;

void MST(int n, vector<int> *adj)
{
    vector<int> parent(n, -1);
    vector<int> key(n, INT_MAX);
    vector<bool> mstSet(n, false);

    key[0] = 0;
    parent[0] = -1;

    // for n-1 edges (due to property of MST -> n nodes and n-1 edges)
    for (int count = 0; count < n - 1; count++)
    {
        int min_key = INT_MAX, u;

        for (int i = 0; i < n; i++)
            if (key[i] < min_key and mstSet[i] == false)
                min_key = key[i];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}