#include <bits/stdc++.h>
using namespace std;

long long int helper(vector<int> &nums, int position, vector<int> &dp)
{
    if (dp[position] != -1)
        return dp[position];

    if (position == nums.size() - 1)
        return 0;

    int k = nums[position];
    long long int steps = INT_MAX;
    int temp_k = 0;
    for (int i = k; i > 0; i--)
    {
        if (position + i < nums.size())
        {
            steps = min(helper(nums, position + i, dp) + 1, steps);
        }
    }

    return dp[position] = steps;
}

int jump(vector<int> &nums)
{
    vector<int> dp(nums.size(), -1);
    return helper(nums, 0, dp);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}