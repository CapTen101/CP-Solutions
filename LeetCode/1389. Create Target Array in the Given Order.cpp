#include <bits/stdc++.h>
using namespace std;

#define my_sizeof(type) ((char *)(&type + 1) - (char *)(&type))
#define loop(typeofx, x, start, end) for (typeofx x = start; x < end; x++)
#define listTraverse(datatypeoflist, x, startList, endList) for (list<datatypeoflist>::iterator x = startList; x != endList; ++x)
#define ll long long int
#define ull unsigned long long int
#define l long int
#define ul unsigned long int
#define start \
    int t;    \
    cin >> t; \
    while (t--)
const ll mod = 1000000007;

class Solution
{
public:
    vector<int> createTargetArray(vector<int> &nums, vector<int> &index)
    {
        vector<int> target(nums.size());
        fill(target.begin(), target.end(), -1);

        fill(target.begin(), target.end(), -1);

        for (int i = 0; i < nums.size(); i++)
        {
            if (target[i] == -1)
                target[index[i]] = nums[i];
            else
            {
            }
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
}