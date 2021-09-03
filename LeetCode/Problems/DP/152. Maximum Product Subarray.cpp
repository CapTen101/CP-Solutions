#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int helper(vector<int> &nums, int &n, int i, int max_prod, unordered_map<int, unordered_map<int, int>> &dp)
    {
        if (n == i)
            return max_prod;

        if (dp.find(i) != dp.end() and dp[i].find(max_prod) != dp[i].end())
            return dp[i][max_prod];

        int choice1 = helper(nums, n, i + 1, max_prod * nums[i], dp);
        int choice2 = helper(nums, n, i + 1, nums[i], dp);

        return dp[i][max_prod] = max({choice1, choice2, max_prod});
    }

    int maxProduct(vector<int> &nums)
    {
        int n = nums.size();
        int max_prod = nums[0];
        unordered_map<int, unordered_map<int, int>> dp;
        return helper(nums, n, 1, max_prod, dp);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}