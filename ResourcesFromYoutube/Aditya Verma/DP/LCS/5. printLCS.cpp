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

int helperMem(int x, int y, string &s1, string &s2, vector<vector<int>> &dp)
{
    if (x == 0 || y == 0)
        return 0;

    if (dp[x][y] != -1)
        return dp[x][y];

    if (s1[x - 1] == s2[y - 1])
    {
        cout << s1[x - 1];
        return dp[x][y] = 1 + helperMem(x - 1, y - 1, s1, s2, dp);
    }
    else
        return dp[x][y] = max(helperMem(x, y - 1, s1, s2, dp), helperMem(x - 1, y, s1, s2, dp));
}

void lcs(int x, int y, string &s1, string &s2)
{
    // Memoization
    // vector<vector<int>> dp(x + 1, vector<int>(y + 1, -1));
    // return helperMem(x, y, s1, s2, dp);

    // Tabulation:
    vector<vector<int>> dp(x + 1, vector<int>(y + 1));

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

    // NOW, traversing the formed dp[][] table in reverse order:
    // If s1[i-1] == s[j-1] -> move to dp[--i][--j]
    // otherwise, move to max(dp[i-1][j], dp[i][j-1])

    int i = x, j = y;
    vector<char> ans;

    while (i >= 0 and j >= 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            ans.push_back(s1[i - 1]);
            i--;
            j--;
        }
        else
        {
            if (dp[i - 1][j] > dp[i][j - 1])
                i--;
            else
                j--;
        }
    }

    for (int k = ans.size() - 1; k >= 0; k--)
    {
        cout << ans[k];
    }

    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s1 = "ABCDGH";
    string s2 = "AEDFHR";

    lcs(6, 6, s1, s2);
}