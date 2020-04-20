// ACCEPTED
#include <bits/stdc++.h>
using namespace std;

#define my_sizeof(type) ((char *)(&type + 1) - (char *)(&type))
#define loop(typeofx, x, start, end) for (typeofx x = start; x < end; ++x)
#define listTraverse(datatypeoflist, x, startList, endList) for (list<datatypeoflist>::iterator x = startList; x != endList; ++x)
#define ll long long int
#define l long int
#define pb push_back
#define MOD 1000000007

int main()
{

    int t;
    cin >> t;

    loop(int, i, 0, t)
    {
        l n, q, currentfloor = 0, floorsum = 0;
        cin >> n >> q;
        l f[q], d[q];

        loop(l, i, 0, q)
        {
            cin >> f[i] >> d[i];
            floorsum += fabs(currentfloor - f[i]);
            currentfloor = f[i];
            floorsum += fabs(currentfloor - d[i]);
            currentfloor = d[i];
        }

        cout << floorsum << endl;
    }
}