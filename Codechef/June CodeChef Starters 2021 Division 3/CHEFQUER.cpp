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

    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int l, r, x;
            cin >> l >> r >> x;

            for (int i = l; i <= r; i++)
            {
                ll yo = x + i - l;
                a[i - 1] += (yo * yo);
            }
        }
        else if (type == 2)
        {
            int y;
            cin >> y;
            cout << a[y - 1] << "\n";
        }
    }
}