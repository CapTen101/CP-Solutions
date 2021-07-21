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

/*
comment: https://leetcode.com/problems/maximum-length-of-repeated-subarray/discuss/413054/ALL-4-ways-Recursion-greater-Top-down-greaterBottom-Up-including-VIDEO-TUTORIAL/890189

"memoization DP gonna have worst case complexity _ O(m * n * min(n,m))
Thus bottom up is recommended here , the confusion might occur _ why memoization not working here ?
Well coz the memoization DP[i][j] and iterative DP[i][j] are storing different values and they have different meaning for this ques.
DP[i][j] of memo _ gives LCS upto index i and j
DP[i][j] of iter _ gives LCS of string ending at i and j , thus here iter DP[m][n] won't give u the answer , answer would be max of DP[i][j] for iter dp"
*/

int helperRecursive(vector<int> &s1, vector<int> &s2, int n, int m, int count)
{
    if (n <= 0 || m <= 0)
        return count;

    int count1 = count;
    int count2, count3;
    if (s1[n - 1] == s2[m - 1])
        count1 = helperRecursive(s1, s2, n - 1, m - 1, count + 1);

    count2 = helperRecursive(s1, s2, n, m - 1, 0);
    count3 = helperRecursive(s1, s2, n - 1, m, 0);

    return max(count1, max(count2, count3));
}

int helperMemoization(vector<int> &s1, vector<int> &s2, int n, int m, int count, vector<vector<vector<int>>> &dp)
{
    if (n == 0 || m == 0)
        return count;

    if (dp[n][m][count] != -1)
        return dp[n][m][count];

    int count1 = count;
    int count2, count3;
    if (s1[n - 1] == s2[m - 1])
        count1 = helperMemoization(s1, s2, n - 1, m - 1, count + 1, dp);

    count2 = helperMemoization(s1, s2, n, m - 1, 0, dp);
    count3 = helperMemoization(s1, s2, n - 1, m, 0, dp);

    return dp[n][m][count] = max(count1, max(count2, count3));
}

int findLength(vector<int> &s1, vector<int> &s2)
{
    /* RECURSIVE
    return helper(s1, s2, s1.size(), s2.size(), 0);
    */

    /* MEMOIZATION
    int n = s1.size();
    int m = s2.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(max(n, m) + 1, -1)));

    return helperMemoization(s1, s2, n, m, 0, dp);
    */

    // TABULATION:
    int n = s1.size();
    int m = s2.size();
    int dp[n + 1][m + 1];
    int max_len = 0;

    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (int i = 0; i <= m; i++)
        dp[0][i] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                max_len = max(max_len, dp[i][j]);
            }
            else
                dp[i][j] = 0; // we'll start counting again since discontinuity is observed.
        }
    }

    return max_len;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}