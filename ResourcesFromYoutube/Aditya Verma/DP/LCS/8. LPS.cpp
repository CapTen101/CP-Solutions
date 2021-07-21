#include <bits/stdc++.h>
using namespace std;

#define my_sizeof(type) ((char *)(&type + 1) - (char *)(&type))
#define FOR(i, start, end) for (int i = start; i < end; i++)
#define ll long long int
#define ull unsigned long long int
#define ul unsigned long int
#define get cin >>
#define print cout <<
#define inarr(s, n, arr)        \
    for (int i = s; i < n; i++) \
        cin >> arr[i];
#define outarr(s, n, arr)       \
    for (int i = s; i < n; i++) \
        cout << arr[i];
#define start \
    int t;    \
    cin >> t; \
    while (t--)

int lcs(string s1, string s2, int x, int y)
{
    int dp[x + 1][y + 1];

    for (int i = 0; i <= x; i++)
        dp[i][0] = 0;
    for (int i = 0; i <= y; i++)
        dp[0][i] = 0;

    for (int i = 1; i <= x; i++)
    {
        for (int j = 1; j <= y; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[x][y];
}

int longestPalindromeSubseq(string s)
{
    string rev = s;
    for (int i = 0; i < s.size() / 2; i++)
    {
        swap(rev[i], rev[s.size() - i - 1]);
    }

    cout << rev;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}