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
        int ans = 0;
        decode(s, ans);
        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);

    Solution sol;
    cout << sol.numDecodings("12");
}