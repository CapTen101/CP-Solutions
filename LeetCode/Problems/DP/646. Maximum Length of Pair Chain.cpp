#include <bits/stdc++.h>
using namespace std;

bool compare(vector<int> &a, vector<int> &b)
{
    return a[1] < b[1];
}

class Solution
{
public:
    // passes only 140/205 cases
    int helper(vector<vector<int>> &p, int i, int last_ele, unordered_map<int, unordered_map<int, int>> &dp)
    {
        if (dp.find(last_ele) != dp.end())
        {
            return dp[last_ele][i];
        }

        if (i >= p.size())
            return dp[last_ele][i] = 0;

        int incl = 0, skip = 0;
        if (last_ele < p[i][0])
        {
            incl = 1 + helper(p, i + 1, p[i][1], dp);
        }

        skip = helper(p, i + 1, last_ele, dp);

        return dp[last_ele][i] = max(incl, skip);
    }

    int findLongestChain(vector<vector<int>> &p)
    {
        /*
        passes only 140/205 cases
        
        unordered_map<int, unordered_map<int, int>> dp;
        sort(p.begin(), p.end());
        return helper(p, 0, INT_MIN, dp);
        */

        /* DP Approach
        sort(p.begin(), p.end());
        vector<int> dp(p.size(), 1);
        if (p.size() == 1)
            return 1;

        int max_len = 0;
        for (int i = 1; i < p.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (p[j][1] < p[i][0] and dp[i] <= dp[j])
                    dp[i] = 1 + dp[j];

                max_len = max(max_len, dp[i]);
            }
        }

        return max_len;
        */

        // Greedy Approach -> similar to my recursion+memoize solution above
        int max_len = 1;                   // init the max_len = 1 since atleast 1 ele WILL be there in our chain
        sort(p.begin(), p.end(), compare); // similar to job-scheduling algo, here sorting is done from second element
        int prev = p[0][1];
        for (int i = 1; i < p.size(); i++)
        {
            if (prev < p[i][0])
            {
                max_len++;
                prev = p[i][1];
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