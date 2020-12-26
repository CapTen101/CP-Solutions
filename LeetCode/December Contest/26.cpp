#include <bits/stdc++.h>
using namespace std;

#define my_sizeof(type) ((char *)(&type + 1) - (char *)(&type))
#define FOR(i, start, end) for (int i = start; i < end; i++)
#define ll long long int
#define ull unsigned long long int
#define l long int
#define ul unsigned long int
#define start \
    int t;    \
    cin >> t; \
    while (t--)

class Solution
{
public:
    void decode(string s, int &ans)
    {
        if (s.empty())
        {
            ans += 1;
            return;
        }

        if (s.size() > 1)
        {
            if (s[0] == '0')
            {
                return;
            }
            else
            {
                string temp = "ab";
                temp[0] = s[0];
                temp[1] = s[1];
                int num = stoi(temp);

                cout << "num: " << num << endl;

                if (num <= 26 && num >= 1)
                {
                    cout << "num 26 and 1 vala" << endl;
                    decode(s.substr(1), ans);
                    decode(s.substr(2), ans);
                }
                else
                    decode(s.substr(1), ans);
            }
        }
        else // if size = 1
        {
            if (s[0] == '0')
                return;
            else
            {
                ans += 1;
                return;
            }
        }
    }

    int numDecodings(string s)
    {
        // recursion code - without memoization
        // int ans = 0;
        // decode(s, ans);
        // return ans;

        // DP code - with memoization:

        if (s[0] == '0')
            return 0;

        int n = s.size();
        vector<int> dp(n + 1, 0);

        // if the single given character is '0'
        dp[0] = 1;

        // if there is single character other than '0'
        dp[1] = 1;

        for (int i = 2; i <= n; i++)
        {
            // dp[i] corresponds to string s[i-1] (i.e. length i)
            if (s[i - 1] - '0' > 0)
                dp[i] = dp[i - 1];

            if (s[i - 2] == '1' || s[i - 2] == '2' && s[i - 1] - '0' < 7)
            {
                dp[i] += dp[i - 2];
            }
        }

        return dp[n];
    }
};

int main()
{
    ios_base::sync_with_stdio(false);

    Solution sol;
    cout << sol.numDecodings("12");
}