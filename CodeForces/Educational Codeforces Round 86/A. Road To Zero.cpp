#include <bits/stdc++.h>
using namespace std;

#define my_sizeof(type) ((char *)(&type + 1) - (char *)(&type))
#define loop(typeofx, x, start, end) for (typeofx x = start; x < end; x++)
#define listTraverse(datatypeoflist, x, startList, endList) for (list<datatypeoflist>::iterator x = startList; x != endList; ++x)
#define ll long long int
#define l long int
#define pb push_back
#define MOD 1000000007

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        ll x, y, a, b;
        cin >> x >> y >> a >> b;

        if (x == 0 || y == 0)
        {
            if (x == 0)
            {
                if (a < b)
                    cout << y * a << "\n";
                else
                    cout << y * b << "\n";
            }
            else
            {
                if (a < b)
                    cout << x * a << "\n";
                else
                    cout << x * b << "\n";
            }
        }
        else
        {
            if (x < y)
            {
                // cout << x * b + (y - x) * a << "\n";
                cout << (y - x) * a + x * b << "\n";
            }
            else if (x > y)
            {
                // cout << y * a + (x - y) * b << "\n";
                cout << (x - y) * a + y * b << "\n";
            }
            else if (x == y)
            {
                // if (2 * x * a < x * b)
                //     cout << 2 * x * b << "\n";
                // else
                    cout << x * b << "\n";
            }
        }
    }
}