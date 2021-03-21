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
    int mod = n % 4;

    if (mod == 0)
        return n;

    else if (mod == 1)
        return 1;

    else if (mod == 2)
        return n + 1;

    else if (mod == 3)
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

        // for (int i = 1; i <= n; i++)
        // {
        //     for (int j = 1; j <= m; j++)
        //     {
        //         ll val = (k + i + j);
        //         ans = (ans ^ val);
        //     }
        // }

        for (ll i = 1; i <= m; i++)
        {
            ans = ans ^ range(k + i + 1, k + i + n);
        }

        cout << ans << "\n";
    }
}