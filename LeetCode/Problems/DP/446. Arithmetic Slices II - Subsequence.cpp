#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // checkout Summet sir's solution here -> https://www.youtube.com/watch?v=XjLT4TaXsgw&ab_channel=Pepcoding
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        int ans = 0;
        int n = nums.size();
        unordered_map<int, int> maps[n];

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                long long int commonDifference = (long long int)nums[i] - (long long int)nums[j];

                // incase we run out of integer bounds, ignore such cases
                if (commonDifference <= INT_MIN || commonDifference >= INT_MAX)
                    continue;

                int APendingInJ = maps[j][commonDifference];
                int APendingInI = maps[i][commonDifference];

                ans += APendingInJ;
                maps[i][commonDifference] = APendingInI + APendingInJ + 1;
            }
        }

        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}