#include <bits/stdc++.h>
using namespace std;

#define my_sizeof(type) ((char *)(&type + 1) - (char *)(&type))
#define loop(typeofx, x, start, end) for (typeofx x = start; x < end; x++)
#define listTraverse(datatypeoflist, x, startList, endList) for (list<datatypeoflist>::iterator x = startList; x != endList; ++x)
#define ll long long int
#define l long int
#define pb push_back

int main()
{

    int t;
    cin >> t;
    ll MOD = 1000000007;

    loop(int, i, 0, t)
    {
        int n;
        unsigned ll a;
        cin >> n >> a;
        unsigned ll p[n] = {1};
        unsigned ll sum = 0;

        unsigned ll m[n][n] = {
            {a, a},
            {a, a}};

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j < i; j++)
            {
                p[i - 1] *= m[j][n - i + 1];
                m[j][n - i + 1] = 0;
            }
            for (int j = 1; j <= i; j++)
            {
                p[i - 1] *= m[i][n - i + j];
                m[i][n - i + j] = 0;
            }
            loop(int, g, 0, n)
            {
                loop(int, h, 0, n)
                {
                    if (!m[g][h] == 0)
                    {
                        m[g][h] *= p[i - 1];
                    }
                }
            }

            sum += (p[i - 1] % MOD);
        }
        cout << sum << endl;
    }
}