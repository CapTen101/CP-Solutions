#include <bits/stdc++.h>
using namespace std;

int helper(vector<int> &nums, int index, vector<int> &dp)
{
    if (index >= nums.size())
        return 0;

    if (dp[index] != -1)
        return dp[index];

    // max(rob house, not rob house)
    return dp[index] = max(nums[index] + helper(nums, index + 2, dp), helper(nums, index + 1, dp));
}

int rob(vector<int> &nums)
{

    int n = nums.size();

    if (n == 1)
        return nums[0];

    if (n == 2)
        return max(nums[0], nums[1]);

    vector<int> dp1(n - 1, -1);

    int last_element = nums[n - 1];
    nums.pop_back();
    int first = helper(nums, 0, dp1);

    vector<int> dp2(n, -1);

    nums.push_back(last_element);
    int second = helper(nums, 1, dp2);

    return max(first, second);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}