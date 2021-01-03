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
    // Faster than 38% submissions: (20ms Solution)
    vector<int> twoSum(vector<int> &v, int k)
    {
        unordered_map<int, int> mp;
        vector<int> ans(2, -1);

        for (int i = 0; i < v.size(); i++)
            mp[v[i]] = i;

        for (int i = 0; i < v.size(); i++)
        {
            if (mp[k - v[i]] && mp[k - v[i]] != i)
            {
                ans[0] = i;
                ans[1] = mp[k - v[i]];
                return {i, mp[k - v[i]]};
            }
        }

        return ans;

        // Faster than 99% solutions: (4ms Solution)

        //
        //

        // map<int,int>mp;
        // for(int i=0;i<nums.size();i++)
        // {
        //     if(mp.count(target-nums[i])>0)
        //       return {mp[target-nums[i]],i};

        //     mp[nums[i]]=i;
        // }
        // return{-1,-1};
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
}