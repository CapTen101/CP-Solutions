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

// DO REVISIT THIS QUESTION FOR REVISION

/*
- t[0][0] -> 0 or infinite_max-1 ? (ANS. doesn't matter)
- "A quick observation: t[0][0] is never used in unbounded Knapsack"
    - "both the for loops start iterating from 1 and in case of unbounded, we look at the previous column of the 
    current row and not the previous row. Just look at the code and you'll get the point."
- "can you take out anything (even 0) from NULL? think about it."
- why INT_MAX is used -> "If you assign 0 to any cell then the global optimum will 
  become 0 and hence you'll get 0 as the answer for all the test cases. To prevent this situation, 
  we assign INT_MAX instead of 0 because you have to find a minimum value other than 0."
- Also no need to initialize second row (as shown by aditya)
- Also since I'm checking if the 'incl' value is -1 or not, hence no need for INT_MAX-1. Can also do with simple INT_MAX.
  Had the check been not applied, it would result in integer overflow after incl+1 operation.
*/

class Solution
{
public:
    int helperMemoize(int A, vector<int> &c, int n, vector<vector<int>> &dp)
    {
        if (n == 0)
            return INT_MAX - 1;
        if (A == 0)
            return 0;

        if (dp[n][A] != -2)
        {
            return dp[n][A];
        }

        if (c[n - 1] <= A)
        {
            int incl = helperMemoize(A - c[n - 1], c, n, dp);
            int excl = helperMemoize(A, c, n - 1, dp);
            return dp[n][A] = min(excl, (incl == INT_MAX - 1) ? INT_MAX - 1 : incl + 1);
        }
        else
            return dp[n][A] = helperMemoize(A, c, n - 1, dp);
    }

    int coinChange(vector<int> &coins, int amount)
    {
        /*
        MEMOIZATION:

        if (amount < 1)
            return 0;

        vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, -2));

        int ans = helperMemoize(amount, coins, coins.size(), dp);
        if (ans == INT_MAX - 1)
            return -1;
        else
            return ans;
            */

        // TABULATION:
        if (amount < 1)
            return 0;

        int n = coins.size();

        vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1));

        for (int i = 0; i <= n; i++)
            dp[i][0] = 0;
        for (int i = 0; i <= amount; i++)
            dp[0][i] = INT_MAX - 1;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= amount; j++)
            {
                if (coins[i - 1] <= j)
                {
                    dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - coins[i - 1]]);
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        if (dp[n][amount] == INT_MAX - 1)
            return -1;
        else
            return dp[n][amount];
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}