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
const ll mod = 1000000007;

// ACCEPTED SOLUTION (I used):

// int len = 2;
// int n = nums.size();
// if (n <= 2)
//     return n;
// for (int i = 2; i < n; i++)
// {
//     if (nums[i] != nums[len - 2] || nums[i] != nums[len - 1])
//     {
//         nums[len] = nums[i];
//         len++;
//     }
// }
// return len;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int len = nums.size();
        int n = nums.size();

        if (n <= 2)
            return n;

        int current_num_count = 1;
        int current_num = nums[0];

        for (int i = 1; i < n; i++)
        {
            if (nums[i] == current_num)
            {
                if (current_num_count < 2)
                {
                    current_num_count++;
                }
                else
                {
                    nums[i] = -100000;
                    len--;
                }
            }
            else
            {
                current_num_count = 1;
                current_num = nums[i];
            }
        }

        for (int i = 0; i < len; i++)
        {
            if (nums[i] == -100000)
            {
                for (; i < nums.size(); i++)
                {
                    nums[i] = nums[i + 1];
                }
                nums.pop_back();
            }

            if (nums[i] == -100000)
            {
                for (; i < nums.size(); i++)
                {
                    nums[i] = nums[i + 1];
                }
                nums.pop_back();
            }
        }

        return len;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);

    vector<int> v = {0, 0, 1, 1, 1, 1, 2, 3, 3, 3};
    Solution obj;
    int num = obj.removeDuplicates(v);

    cout << num << endl;

    FOR(i, 0, v.size())
    {
        cout << v[i];
    }

    cout << endl;

    cout << v.size() << endl;
}