#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int helper(vector<int> &nums, int prev, int currIndex, vector<vector<int>> &dp)
    {
        if (dp[currIndex][prev + 10001] != -1)
            return dp[currIndex][prev + 10001];

        if (currIndex == nums.size())
        {
            return 0;
        }

        if (nums[currIndex] > prev) // if greater, 2 choices -> take or don't take -> return max(take, don't take)
            return dp[currIndex][prev + 10001] = max(1 + helper(nums, nums[currIndex], currIndex + 1, dp), helper(nums, prev, currIndex + 1, dp));
        else // don't take the element
            return dp[currIndex][prev + 10001] = helper(nums, prev, currIndex + 1, dp);
    }

    int lengthOfLIS(vector<int> &nums)
    {
        /* Memoization Approach
        const int inf = INT_MAX;
        vector<vector<int>> dp(nums.size()+1, vector<int>(20001, -1));
        return helper(nums, -10001, 0, dp);
        */

        // Tabulation approach

        // init with because every ele is a inc subsequence in itself
        // dp[i] gives the length of LIS upto ith index
        vector<int> dp(nums.size(), 1);
        if (nums.size() == 1)
            return dp[0];
        int max_len = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            // start from 1 since dp[0] will always be max to max 1
            for (int j = 0; j < i; j++)
            {
                // first condition -> gives us an increasing subsequence
                // second condition -> gives us the LONGEST subsequence. it tells us whether including the element at j will gives the longest subsequence or not
                if (nums[i] > nums[j] and dp[i] <= dp[j])
                    dp[i] = 1 + dp[j];

                max_len = max(max_len, dp[i]);
            }
        }

        return max_len;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}