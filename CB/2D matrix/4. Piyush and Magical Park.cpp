#include <bits/stdc++.h>
using namespace std;

#define my_sizeof(type) ((char *)(&type + 1) - (char *)(&type))
#define FOR(i, start, end) for (int i = start; i < end; i++)
#define ll long long int
#define ull unsigned long long int
#define l long int
#define ul unsigned long int
#define start \
    int t;    \
    cin >> t; \
    while (t--)
const ll mod = 1000000007;

int main()
{
    ios_base::sync_with_stdio(false);

    int n, m, k, s;
    cin >> n >> m >> k >> s;

    if (s < k)
    {
        cout << "No" << endl;
        return 0;
    }

    // setting n rows
    vector<vector<char>> park(n);

    // setting m columns
    for (int i = 0; i < n; i++)
        park[i].resize(m);

    // taking input
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> park[i][j];
    }

    int power = s;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (park[i][j] == '.')
                power -= 2;
            else if (park[i][j] == '#')
                break;
            else if (park[i][j] == '*')
                power += 5;

            power -= 1;

            if (power < k)
            {
                cout << "No" << endl;
                return 0;
            }
        }
    }

    if (power >= k)
    {
        cout << "Yes" << endl;
        cout << power << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}