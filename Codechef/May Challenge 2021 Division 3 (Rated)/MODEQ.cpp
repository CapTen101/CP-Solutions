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
        int n, m;
        cin >> n >> m;
        int ans = 0;

        vector<int> arr(n + 1, 1);

        FOR(i, 2, n + 1)
        {
            int rem = m % i;
            ans += arr[rem];
            for (int j = rem; j < n + 1; j += i)
            {
                arr[j]++;
            }
        }

        cout << ans << endl;
    }
}