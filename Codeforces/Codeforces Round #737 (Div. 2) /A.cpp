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
        int n;
        cin >> n;

        vector<ll> a(n);

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        ll mx = a[0];
        ll sum = a[0];
        for (int i = 1; i < n; i++)
        {

            sum += a[i];
            mx = max(mx, a[i]);
        }

        double ans = mx + (double)((sum - mx) / (n - 1));
        // cout << "ans" << ans;
        cout << setprecision(10) << ans << endl;
    }
}