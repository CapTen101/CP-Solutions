#include <bits/stdc++.h>
using namespace std;

#define my_sizeof(type) ((char *)(&type + 1) - (char *)(&type))
#define FOR(i, start, end) for (int i = start; i < end; i++)
#define ll long long int
#define ull unsigned long long int
#define l long int
#define ul unsigned long int
#define start \
    int t;    \
    cin >> t; \
    while (t--)
const ll mod = 1000000007;

int main()
{
    ios_base::sync_with_stdio(false);

    start
    {
        ll a, b, c;
        cin >> a >> b >> c;

        if (a == b == c)
        {
            cout << 0 << endl;
            continue;
        }

        int max_all = max(a, max(b, c));
        int min_all = min(a, min(b, c));

        if ((max_all - min_all) <= 1)
        {
            cout << 0 << endl;
            continue;
        }
        max_all--;
        min_all++;

        cout << 2 * (max_all - min_all) << endl;
    }
}