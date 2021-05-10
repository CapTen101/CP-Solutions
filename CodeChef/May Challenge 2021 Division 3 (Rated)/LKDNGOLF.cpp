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
        ll n, x, k;
        cin >> n >> x >> k;

        bool enter = false;

        // bool first = ((x / k) + 1) == (int)(((x / k) + 1));
        // bool second = ((n + 1 - x + k) / k) == (int)((n + 1 - x + k) / k);

        if (!(x % k)) // if int
        {
            enter = true;
        }
        else if (!((n + 1 - x + k) % k)) // if int
        {
            enter = true;
        }

        cout << (enter ? "YES" : "NO") << endl;
    }
}