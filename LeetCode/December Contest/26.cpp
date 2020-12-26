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
    int decode(string s, int ans)
    {
        if (s.empty())
            return ans;

        if (s.size() > 1)
        {
            if (s[0] == '0')
            {
                return decode(s.substr(1), ans);
            }
            else
            {
                string temp;
                temp.push_back(s[0]);
                temp.push_back(s[1]);
                int num = stoi(temp);
                cout << temp << endl;

                if (num <= 26 && num >= 1)
                {
                    return decode(s.substr(1), ++ans) + decode(s.substr(2), ++ans);
                }
                else
                    return decode(s.substr(1), ++ans);
            }
        }
        else // if size = 1
        {
            if (s[0] == '0')
                return decode(s.substr(1), ans);
            else
                return decode(s.substr(1), ++ans);
        }
    }

    int numDecodings(string s)
    {
        return decode(s, 0);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);

    Solution sol;
    cout << sol.numDecodings("226");
}