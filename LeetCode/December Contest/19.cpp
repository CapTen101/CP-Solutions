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
    string decodeAtIndex(string S, int K)
    {
        long long size = 0;
        //length of decoded string
        for (int i = 0; i < S.size(); i++)
        {
            if (isalpha(S[i]))
            {
                size++;
            }
            else if (isdigit(S[i]))
            {
                size *= S[i] - '0';
            }
        }

        for (int i = S.size() - 1; i >= 0; i--)
        {
            K %= size;

            if (K == 0 && isalpha(S[i]))
            {
                string ans = "";
                ans.push_back(S[i]);
                return ans;
            }

            //means string before it has been repeated digit-1 times
            else if (isdigit(S[i]))
            {
                size /= S[i] - '0';
            }

            //simply decrease length
            else
            {
                size--;
            }
        }
        return "";
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
}