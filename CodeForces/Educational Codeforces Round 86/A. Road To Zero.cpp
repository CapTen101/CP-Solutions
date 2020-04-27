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
                cout << y * a << "\n";
            else
                cout << x * a << "\n";
        }
        else
        {
            if (x < y)
                cout << (y - x) * a + x * b << "\n";
            else if (x > y)
                cout << (x - y) * a + y * b << "\n";
            else if (x == y)
            {
                if (2 * a > b)
                    cout << x * b << "\n";
                else
                    cout << 2 * x * a << "\n";
            }
        }
    }
}