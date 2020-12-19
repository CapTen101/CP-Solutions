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
    bool increasingTriplet(vector<int> &nums)
    {
        int first = INT_MAX;
        int second = INT_MAX;

        for (int i : nums)
        {
            if (i <= first)
                first = i;
            else if (i >= second)
                second = i;
            else
                return true;
        }

        return false;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
}