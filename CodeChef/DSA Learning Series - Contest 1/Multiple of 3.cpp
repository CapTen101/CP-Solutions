#include <bits/stdc++.h>
using namespace std;

#define my_sizeof(type) ((char *)(&type + 1) - (char *)(&type))
#define loop(typeofx, x, start, end) for (typeofx x = start; x < end; ++x)
#define listTraverse(datatypeoflist, x, startList, endList) for (list<datatypeoflist>::iterator x = startList; x != endList; ++x)
#define ll long long int
#define pb push_back

int main()
{

    int t;
    cin >> t;

    loop(int, i, 0, t)
    {
        ll k;
        cin >> k;

        if (k == 2)
        {
            int d0, d1;
            cin >> d0 >> d1;
            if ((d0 + d1) % 3 == 0)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
            continue;
        }

        long d[k];
        cin >> d[0] >> d[1];

        long sum = d[0] + d[1];

        loop(ll, i, 2, k)
        {
            d[i] = sum % 10;
            sum += d[i];
        }

        if (sum % 3 == 0)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}