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

// int minimumDeletions(string s)
// {
//     int right_0 = count(s.begin(), s.end(), '0');

//     int left_1 = 0;

//     int n = s.size();

//     int res = INT_MAX;

//     for (int i = 0; i < n; i++)
//     {
//         if (s[i] == '0')
//         {
//             right_0 -= 1;
//         }
//         else
//         {
//             left_1 += 1;
//         }

//         res = min(res, right_0 + left_1);
//     }

//     return res;
// }

bool check(string s)
{
    bool fail = 0, success = 0;

    if (s[0] == '1')
        fail = 1;

    FOR(i, 1, s.length() - 1)
    {
        if (fail)
        {
            if (s[i] == '0' && s[i + 1] == '0')
            {
                return false;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);

    start
    {
        string s;
        cin >> s;

        bool success = 0, fail = 0;

        FOR(i, 1, s.length())
        {
            if (s[i - 1] == '1' && s[i] == '1')
            {
                fail = 1;
            }
            if (fail)
            {
                if (s[i - 1] == '0' && s[i] == '0')
                    success = 0;
            }
        }

        cout << (success ? "YES" : "NO") << endl;
    }
}