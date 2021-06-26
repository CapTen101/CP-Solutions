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
    cout.tie(NULL);

    start
    {
        int n;
        cin >> n;
        int ans = 0;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        int i = 0, j = i + 1;
        while (i < j && i < n && j < n)
        {
            if ((a[i] * a[j]) == (i + j + 2))
                ans++;

            if (j == n - 1)
            {
                i++;
                j = i + 1;
                continue;
            }

            j++;
        }

        cout << ans << endl;
    }
}