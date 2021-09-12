#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestArithSeqLength(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return 0;

        int max_len = 0;
        /* SLOW APPROACH (using array of hashmaps):
        
        unordered_map<int, int> maps[n];
        
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                int commonDiff = nums[i] - nums[j];
                
                int len = 2;
                
                if(maps[j].find(commonDiff) != maps[i].end())
                    len = maps[j][commonDiff] + 1;
                maps[i][commonDiff] = len;
                
                max_len = max(max_len, len);
            }
        }
        */

        int dp[n][1001];
        memset(dp, 0, sizeof(dp));

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                int commonDiff = nums[i] - nums[j];

                dp[i][commonDiff + 500] = dp[j][commonDiff + 500] + 1;
                max_len = max(max_len, dp[i][commonDiff + 500]);
            }
        }
        return max_len + 1; // doing +1 because we ignore the first element and start counting from the second one.
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}