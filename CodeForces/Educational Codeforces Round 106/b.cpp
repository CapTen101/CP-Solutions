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
        string s;
        cin >> s;

        bool success = 1, fail = 0;

        FOR(i, 1, s.length())
        {
            if (s[i - 1] == '1' && s[i] == '1')
            {
                fail = 1;
            }
            if (fail)
            {
                if (s[i - 1] == '0' && s[i] == '0')
                {
                    success = 0;
                    break;
                }
            }
        }

        cout << (success ? "YES" : "NO") << endl;
    }
}