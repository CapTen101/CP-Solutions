#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> OURanswer(2);

        sort(nums.begin(), nums.end());
        int s = 0;
        int e = nums.size() - 1;

        while (s < e)
        {
            if (nums[s] + nums[e] > target)
            {
                e--;
            }
            else if (nums[s] + nums[e] < target)
            {
                s++;
            }
            else
            {
                OURanswer[0] = s;
                OURanswer[1] = e;
            }
        }

        return OURanswer;
    }
};

int main()
{
}