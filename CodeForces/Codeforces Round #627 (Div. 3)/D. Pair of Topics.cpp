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

    int n;
    cin >> n;
    vector<ll> a(n), b(n), c(n);

    loop(int, i, 0, n)
    {
        cin >> a[i];
    }
    loop(int, i, 0, n)
    {
        cin >> b[i];
    }

    loop(int, i, 0, n)
    {
        c[i] = a[i] - b[i];
    }

    sort(c.begin(), c.end());

    int s = 0;
    int e = n - 1;
    int ans = 0;

    loop(int, i, 0, n)
    {
        if (c[s] + c[e] > 0)
        {
            ans++;
        }
        else
        {
            s++;
        }
    }
    cout << ans << "\n";
}