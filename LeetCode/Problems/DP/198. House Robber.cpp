#include <bits/stdc++.h>
using namespace std;

int helperRecursive(vector<int> &nums, int index, vector<int> &dp)
{
    if (index >= nums.size())
        return 0;

    if (dp[index] != -1)
        return dp[index];

    // max(rob house, not rob house)
    return dp[index] = max(nums[index] + helperRecursive(nums, index + 2, dp), helperRecursive(nums, index + 1, dp));
}

int rob(vector<int> &nums)
{
    if (nums.size() == 1)
        return nums[0];

    if (nums.size() == 2)
        return max(nums[0], nums[1]);

    vector<int> dp(nums.size(), -1);
    return helperRecursive(nums, 0, dp);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}