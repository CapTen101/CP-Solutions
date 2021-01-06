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
    int findKthPositive(vector<int> &v, int k)
    {
        int n = v.size(), miss = 0;
        vector<int> nums;

        if (v[0] != 1)
        {
            miss = 1;

            while (miss < v[0])
            {
                nums.push_back(miss);
                miss++;
            }

            if (k <= nums.size())
                return nums[k - 1];
        }

        for (int i = 0; i < n - 1; i++)
        {
            if (v[i + 1] - v[i] > 1)
            {
                miss = v[i] + 1;
                while (miss < v[i + 1])
                {
                    nums.push_back(miss);
                    miss++;
                }

                if (k <= nums.size())
                    return nums[k - 1];
            }
        }

        if (nums.size() < k)
        {
            return v[n - 1] + k;
        }

        return -1;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);

    vector<int> v = {1, 2, 3, 4};

    Solution sol;
    cout << sol.findKthPositive(v, 2) << endl;
}