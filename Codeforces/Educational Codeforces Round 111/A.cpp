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
        int s;
        cin >> s;

        set<int> n;

        if (s == 1)
        {
            cout << 1 << endl;
            continue;
        }

        int siz = 0;
        int last = 1;
        s--;

        while (s > 0)
        {
            if (s == last + 1 || s == last + 2)
            {
                siz++;
                break;
            }

            if (s % 2 == 0) // even
            {
                siz++;
                last += 2;
                s -= (last);
            }
            else // odd
            {
                siz++;
                last += 2;
                s -= (last);
            }
        }

        cout << siz + 1 << endl;
    }
}