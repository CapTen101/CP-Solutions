#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void kadane(vector<int> &nums, int &normal_max)
    {
        int temp_max = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            temp_max += nums[i];
            if (temp_max < nums[i])
                temp_max = nums[i];

            normal_max = max(temp_max, normal_max);
        }
    }

    int maxSubarraySumCircular(vector<int> &nums)
    {
        int normal_max = INT_MIN, circular_max = INT_MIN, total_sum = 0;

        for (int i = 0; i < nums.size(); i++)
            total_sum += nums[i];

        // maximum acc to normal array
        kadane(nums, normal_max);

        // maximum acc to circular array
        // first, inverting the signs
        for (int i = 0; i < nums.size(); i++)
            nums[i] *= -1;

        // get the max of inverted array, hence the min of the actual array
        kadane(nums, circular_max);
        // inverting again to convert to minimum array sum
        circular_max *= -1;
        int ans = max(total_sum - circular_max, normal_max);
        return total_sum - circular_max == 0 ? normal_max : ans; //first condition is the corner case (all -ve nums)
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}