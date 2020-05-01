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
        vector<unsigned ll> w;

        loop(int, i, 1, n + 1)
        {
            w.pb(pow(2, i));
        }

        int s = 0;
        int e = n - 1;

        vector<unsigned ll> one;
        vector<unsigned ll> two;

        loop(int, i, 0, n)
        {
            
        }

        if ((n / 2) % 3 != 0)
        {
        }
    }
}