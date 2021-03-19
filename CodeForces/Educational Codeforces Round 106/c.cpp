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

int main()
{
    ios_base::sync_with_stdio(false);

    start
    {
        int n;
        cin >> n;

        vector<ll> c(n);
        for (int i = 0; i < n; i++)
            cin >> c[i];

        if (n == 2)
        {
            cout << 2 * c[0] + 2 * c[1] << endl;
            continue;
        }
        else
        {
            cout << n * c[0] + n * c[1] << endl;
        }
    }
}