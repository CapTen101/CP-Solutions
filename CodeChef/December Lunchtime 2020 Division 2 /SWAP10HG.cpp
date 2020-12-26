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

int main()
{
    ios_base::sync_with_stdio(false);
    start
    {
        int n;
        cin >> n;

        string s, p;
        cin >> s >> p;

        if (s.size() != p.size())
        {
            cout << "No" << endl;
            continue;
        }

        int one = 0;
        int zero = 0;
        int one_sum = 0, zero_sum = 0;

        vector<pair<int, int>> count;

        int low = 0;
        int end = n - 1;

        int ans = 0;

        for (int i = 0; i < n && ans >= 0; i++)
        {
            if (s[i] != p[i])
            {

                if (s[i] == '1' && p[i] == '0')
                    ans++;
                else
                    ans--;
            }
        }
        if (ans < 0 || ans > 0)
        {
            cout << "No" << endl;
            continue;
        }
        else
            cout << "Yes" << endl;
    }
}