// Problem Statement: https://www.spoj.com/problems/BUSYMAN/

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

bool compare(pair<int, int> p1, pair<int, int> p2)
{
    return p1.second < p2.second;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<pair<int, int>> act(N);

    for (int i = 0; i < N; i++)
    {
        int m, n;
        cin >> m >> n;
        act[i] = make_pair(m, n);
    }

    sort(act.begin(), act.end(), compare);

    int ans = 1;
    int end = act[0].second;

    for (int i = 1; i < N; i++)
    {
        if (end <= act[i].first)
        {
            ans++;
            end = act[i].second;
        }
    }

    cout << ans << endl;
    act.clear();
}