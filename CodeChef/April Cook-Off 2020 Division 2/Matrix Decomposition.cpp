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

    while(t--)
    {
        int n;
        unsigned ll a;
        cin >> n >> a;
        unsigned ll p[n] = {1};
        unsigned ll sum = 0;

        unsigned ll m[n][n];

        loop(int, g, 0, n)
        {
            loop(int, h, 0, n)
            {
                m[g][h] = a;
            }
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j < i; j++)
            {
                if (!m[j][n - i + 1] == 0)
                {
                    p[i - 1] *= m[j][n - i + 1];
                    m[j][n - i + 1] = 0;
                }
            }
            for (int j = 1; j <= i; j++)
            {
                if (!m[i][n - i + j] == 0)
                {
                    p[i - 1] *= m[i][n - i + j];
                    m[i][n - i + j] = 0;
                }
            }
            loop(int, g, 0, n)
            {
                loop(int, h, 0, n)
                {
                    m[g][h] *= p[i - 1];
                }
            }

            sum += (p[i - 1] % MOD);
        }
        cout << sum << endl;
    }
}

// RAHUL's SOLUTION

// #include <iostream>
// using namespace std;

// #define ll long long int


// long long int powerr(long long int a, int p)
// {
//     if (p == 1)
//     {
//         return a;
//     }
//     else if (p % 2 == 0)
//     {
//         long long int qwe = powerr(a, (p / 2));
//         qwe = qwe * qwe;
//         qwe = qwe % 1000000007;
//         return qwe;
//     }
//     else
//     {
//         long long int qwe = powerr(a, (p / 2));
//         qwe = qwe * qwe;
//         qwe = qwe % 1000000007;
//         qwe = qwe * a;
//         qwe = qwe % 1000000007;
//         return qwe;
//     }
// }
// int solve(long long int a, int p, long long int pf)
// {
//     a = a * pf;
//     a = a % 1000000007;
//     long long int ans = powerr(a, p);
//     return ans;
// }
// int main()
// {
//     int t;
//     cin >> t;
//     for (int u = 1; u <= t; u++)
//     {
//         ll n, a;
//         cin >> n >> a;
//         ll arr[n + 1];
//         ll sum = 0;
//         ll productfactor = 1;
//         for (int i = 1; i <= n; i++)
//         {
//             ll yyyyy = solve(a, (2 * i) - 1, productfactor);
//             sum = sum + yyyyy;
//             sum = sum % 1000000007;
//             productfactor *= yyyyy;
//             productfactor = productfactor % 1000000007;
//         }

//         cout << sum << endl;
//     }

//     return 0;
// }