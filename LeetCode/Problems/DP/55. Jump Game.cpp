#include <bits/stdc++.h>
using namespace std;

bool helper(vector<int> &nums, int position)
{
    if (position == nums.size() - 1)
        return true;

    if (nums[position] == 0)
        return false;

    int k = nums[position];
    bool condition = false;
    while (k)
    {
        // cout << i << " ";
        if ((position + k) < nums.size())
            condition = helper(nums, position + k);

        if (condition)
            break;

        k--;
    }

    return condition;
}

bool canJump(vector<int> &nums)
{
    return helper(nums, 0);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> v = {2, 3, 1, 1, 4};

    return canJump(v);
}