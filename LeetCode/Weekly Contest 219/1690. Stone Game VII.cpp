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
    int stoneGameVII(vector<int> &s)
    {

        int n = s.size(); // initial number of elements in the vector
        int total_sum = 0;

        for (int i = 0; i < n; i++)
            total_sum += s[i];

        int temp_sum = total_sum;

        int a = 0; // score of alice
        int b = 0; // score of bob

        int i = 1; // iterator
        while (i <= n)
        {
            if (s[s.size() - 1] >= s[0])
            {
                if (i % 2 != 0) // alice's turn
                {
                    temp_sum = temp_sum - s[0];
                    a += temp_sum;
                    s.erase(s.begin() + 0);
                }
                else // bob's turn
                {
                    temp_sum = temp_sum - s[0];
                    b += temp_sum;
                    s.erase(s.begin() + 0);
                }
            }
            else
            {
                if (i % 2 != 0) // alice's turn
                {
                    temp_sum = temp_sum - s[s.size() - 1];
                    a += temp_sum;
                    s.erase(s.begin() + s.size() - 1);
                }
                else // bob's turn
                {
                    temp_sum = temp_sum - s[s.size() - 1];
                    b += temp_sum;
                    s.erase(s.begin() + s.size() - 1);
                }
            }
            i++;
        }

        if ((a - b) >= 0)
            return a - b;
        else
            return b - a;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
}