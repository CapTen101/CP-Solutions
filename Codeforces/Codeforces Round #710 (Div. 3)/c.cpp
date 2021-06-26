#include <bits/stdc++.h>
using namespace std;

#define my_sizeof(type) ((char *)(&type + 1) - (char *)(&type))
#define FOR(i, start, end) for (int i = start; i < end; i++)
#define ll long long int
#define ull unsigned long long int
#define ul unsigned long int
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
        string a, b;
        cin >> a >> b;

        ll ans = 0;

        if (a == b)
        {
            cout << 0 << endl;
            continue;
        }
        else if (a.empty())
        {
            if (b.empty())
            {
                cout << 0 << endl;
                continue;
            }
            else
            {
                cout << b.size() << endl;
                continue;
            }
        }
        else if (b.empty())
        {
            if (a.empty())
            {
                cout << 0 << endl;
                continue;
            }
            else
            {
                cout << a.size() << endl;
                continue;
            }
        }
    }
}