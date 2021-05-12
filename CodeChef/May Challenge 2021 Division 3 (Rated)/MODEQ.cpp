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
        int count = 0;

        // if (m > n)
        // {
        //     cout << n * (n - 1) << endl;
        //     continue;
        // }

        // int limit = min(m, n);

        if (m > n)
        {
            FOR(i, 1, n + 1)
            {
                FOR(j, i + 1, n + 1)
                {
                    if (((m % i) % j) == ((m % j) % i))
                    {
                        count++;
                        // cout << "count" << count << " ";
                        // cout << "mod:" << (m % j) % i << " " << i << " " << j << endl;
                    }
                    // if (j % i == 0)
                    //     count++;
                }
            }
        }
        else
        {
            count = (n - m + 1) * (n - m) - n + m - 1;
            FOR(i, 1, m)
            {
                FOR(j, i + 1, m)
                {
                    if (((m % i) % j) == ((m % j) % i))
                    {
                        count++;
                        // cout << "count" << count << " ";
                        // cout << "mod:" << (m % j) % i << " " << i << " " << j << endl;
                    }
                    // if (j % i == 0)
                    //     count++;
                }
            }
        }

        cout << count << endl;
    }
}