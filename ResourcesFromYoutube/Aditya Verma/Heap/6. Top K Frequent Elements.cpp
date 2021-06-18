#include <bits/stdc++.h>
using namespace std;

#define my_sizeof(type) ((char *)(&type + 1) - (char *)(&type))
#define FOR(i, start, end) for (int i = start; i < end; i++)
#define ll long long int
#define ull unsigned long long int
#define ul unsigned long int
#define get cin >>
#define print cout <<
#define inarr(s, n, arr)        \
    for (int i = s; i < n; i++) \
        cin >> arr[i];
#define outarr(s, n, arr)       \
    for (int i = s; i < n; i++) \
        cout << arr[i];
#define start \
    int t;    \
    cin >> t; \
    while (t--)

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        if (nums.empty())
            return nums;

        int n = nums.size();

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++)
        {
            mp[nums[i]]++;
        }

        for (auto i = mp.begin(); i != mp.end(); i++)
        {
            minHeap.push({i->second, i->first});
            if (minHeap.size() > k)
            {
                minHeap.pop();
            }
        }

        vector<int> ans;
        while (minHeap.size())
        {
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}