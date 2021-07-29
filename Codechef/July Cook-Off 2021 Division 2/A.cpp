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

ll calc_gcd(ll x, ll y)
{
    if (y == 0)
        return x;

    return calc_gcd(y, x % y);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    start
    {
        ll x, y;
        cin >> x >> y;

        if (x == 1 and y == 1)
        {
            cout << 2 << endl;
            continue;
        }

        if (x == 1 || y == 1)
        {
            if (x == 1)
            {
                if (y % 2 == 0)
                {
                    cout << 1 << endl;
                    continue;
                }
                else
                {
                    cout << 2 << endl;
                    continue;
                }
            }
            else
            {
                if (x % 2 == 0)
                {
                    cout << 1 << endl;
                    continue;
                }
                else
                {
                    cout << 2 << endl;
                    continue;
                }
            }
        }

        if (x > y)
            swap(x, y);

        if (calc_gcd(x, y) > 1)
        {
            cout << 0 << endl;
            continue;
        }
        else if (calc_gcd(x, y + 1) > 1 || calc_gcd(x + 1, y) > 1)
        {
            cout << 1 << endl;
        }
        else
        {
            cout << 2 << endl;
        }

        // if (x % y == 0 || y % x == 0)
        // {
        //     cout << 0 << endl;
        //     continue;
        // }

        // if (x % 2 == 0 and y % 2 == 0)
        //     cout << 0 << endl;
        // else if (x % 2 == 0 and y % 2 != 0)
        //     cout << 1 << endl;
        // else
        //     cout << 2 << endl;

        // ll mn = min(x, y);
        // ll mx = max(x, y);

        // ll div = mx / mn;
        // ll ans = min(mx - mn, mx - mn * div);

        // int mod = mx % mn;
        // if (mod > mn / 2)
        // {
        //     cout << mn - mod << endl;
        //     continue;
        // }
        // else
        // {
        //     cout << mod << endl;
        // }
    }
}