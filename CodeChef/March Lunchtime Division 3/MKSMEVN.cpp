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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    start
    {
        ll n;
        cin >> n;
        vector<int> v;
        bool convertible = false;
        bool has123 = false;

        int op = 0; // number of operations

        ll odd_num = 0;

        FOR(i, 0, n)
        {
            ll a;
            cin >> a;
            v.push_back(a);

            if (a == 2)
                has123 = true;

            if (a % 2 != 0)
                odd_num++;
        }

        if (odd_num % 2 == 0)
        {
            cout << 0 << endl;
            continue;
        }
        else
        {
            // FOR(i, 0, n)
            // {
            //     if (v[i] % 2 != 0)
            //     {
            //         int p = max(0, v[i] / 2 - 1);
            //         v[i] = pow(v[i], p);
            //         op++;

            //         if (v[i] % 2 == 0)
            //         {
            //             convertible = true;
            //             break;
            //         }
            //     }
            // }
            if (has123)
                cout << 1 << endl;
            else
                cout << -1 << endl;
            continue;
        }

        // if (convertible)
        //     cout << op << endl;
        // else
        //     cout << -1 << endl;
    }
}