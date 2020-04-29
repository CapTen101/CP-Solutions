// ACCEPTED

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

    int n, m, a, b;
    cin >> n >> m >> a >> b;

    if (b / m < a)
    {
        if (n % m == 0)
            cout << (b * (n / m));
        else
        {
            if (b < a * (n % m))
                cout << (b * (n / m)) + b;
            else
            {
                cout << (b * (n / m)) + a * (n % m);
            }
        }
    }
    else
    {
        cout << a * n;
    }
}