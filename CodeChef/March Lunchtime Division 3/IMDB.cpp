#include <bits/stdc++.h>
using namespace std;

#define my_sizeof(type) ((char *)(&type + 1) - (char *)(&type))
#define FOR(i, start, end) for (int i = start; i < end; i++)
#define ll long long int
#define ull unsigned long long int
#define ul unsigned long int
#define start \
    int t;    \
    cin >> t; \
    while (t--)

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, x;
    cin >> n >> x;
    map<ll, ll> m;
    vector<ll> v;
    for (int i = 0; i < n; i++)
    {
        ll s, r;
        cin >> s >> r;
        v.push_back(r);
        m.insert({r, s});
    }

    sort(v.begin(), v.end());

    for (int i = v.size() - 1; i >= 0; i--)
    {
        if (m[v[i]] <= x)
        {
            cout << v[i] << endl;
            break;
        }
    }
}