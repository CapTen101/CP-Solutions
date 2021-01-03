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
    // 12ms Solution:
    vector<int> twoSum(vector<int> &num, int k)
    {
        int s = 0;
        int e = num.size() - 1;

        while (s < e)
        {
            if (num[s] + num[e] == k)
                return {s + 1, e + 1};
            else if (num[s] + num[e] < k)
            {
                s++;
                continue;
            }
            else if (num[s] + num[e] > k)
            {
                e--;
                continue;
            }
        }

        return {-1, -1};
    }

    // 0ms Solution:

    //

    //     class Solution {
    // public:
    //     vector<int> twoSum(vector<int>& numbers, int target) {
    //         for (int i = 0, j = numbers.size() - 1; i < j;)
    //         {
    //             if (numbers[i] + numbers[j] > target)
    //                 j--;
    //             else if (numbers[i] + numbers[j] < target)
    //                 i++;
    //             else
    //                 return {i + 1, j + 1};
    //         }

    //         return {};
    //     }
    // };
};

int main()
{
    ios_base::sync_with_stdio(false);
}