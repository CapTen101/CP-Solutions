#include <bits/stdc++.h>
using namespace std;

#define my_sizeof(type) ((char *)(&type + 1) - (char *)(&type))
#define loop(typeofx, x, start, end) for (typeofx x = start; x < end; x++)
#define listTraverse(datatypeoflist, x, startList, endList) for (list<datatypeoflist>::iterator x = startList; x != endList; ++x)
#define ll long long int
#define l long int
#define pb push_back
#define start \
    int t;    \
    cin >> t; \
    while (t--)
const ll mod = 1000000007;

int main()
{
    ios_base::sync_with_stdio(false);

    start
    {
        int n;
        cin >> n;
        vector<int> x(n);
        loop(int, i, 0, n)
        {
            cin >> x[i];
        }

        if (n == 1)
        {
            cout << "1 1"
                 << "\n";
            continue;
        }
        else if (n == 2)
        {
            if (x[1] - x[0] > 2)
                cout << "1 1"
                     << "\n";
            else
                cout << "1 2"
                     << "\n";
        }
        else
        {
            
        }
    }
}
