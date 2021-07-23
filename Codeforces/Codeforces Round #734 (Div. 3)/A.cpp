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

        if (n % 3 == 0)
        {
            int x = n / 3;
            cout << x << " " << x << endl;
            continue;
        }
        else if (n % 3 == 1)
        {
            int x = n / 3;
            cout << x + 1 << " " << x << endl;
            continue;
        }
        else
        {
            int x = n / 3;
            cout << x << " " << x + 1 << endl;
            continue;
        }
    }
}