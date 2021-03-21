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

int find(int n)
{
    int val = n % 4;

    if (val == 0)
        return n;

    else if (val == 1)
        return 1;

    else if (val == 2)
        return n + 1;

    else if (val == 3)
        return 0;
}

int range(int l, int r)
{
    return (find(l - 1) ^ find(r));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    start
    {
        ll n, m, k;
        cin >> n >> m >> k;

        int ans = 0;

        for (ll i = 1; i <= m; i++)
        {
            ans = ans ^ range(k + i + 1, k + i + n);
        }

        cout << ans << "\n";
    }
}