#include <bits/stdc++.h>
using namespace std;

#define my_sizeof(type) ((char *)(&type + 1) - (char *)(&type))
#define loop(typeofx, x, start, end) for (typeofx x = start; x < end; x++)
#define listTraverse(datatypeoflist, x, startList, endList) for (list<datatypeoflist>::iterator x = startList; x != endList; ++x)
#define ll long long int
#define l long int
#define pb push_back
const ll mod = 1000000007;

int main()
{
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int a[n][n];

        loop(int, i, 0, n)
        {
            loop(int, j, 0, n)
            {
                cin >> a[i][j];
            }
        }

        bool bed = 1, safe = 1;

        loop(int, i, 0, n)
        {
            loop(int, j, 1, n)
            {
                if (a[i][j] == bed)
                {
                    safe = 0;
                    break;
                }
                if (safe == 0)
                {
                    cout << "UNSAFE";
                    break;
                }
            }
            bed = a[i][0];
        }
        if (safe)
        {
            cout << "SAFE"
                 << "\n";
        }
        else
        {
            cout << "UNSAFE"
                 << "\n";
        }
    }
}