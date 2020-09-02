#include <bits/stdc++.h>
using namespace std;

#define start \
    int t;    \
    cin >> t; \
    while (t--)

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int m;
    cin >> n >> m;

    vector<pair<int, int>> fact;

    for (int i = 0; i < m; i++)
    {
        int first, second;
        cin >> first >> second;
        fact.push_back({first, second});
    }
}