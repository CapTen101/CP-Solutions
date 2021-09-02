#include <bits/stdc++.h>
using namespace std;

class Compare
{
public:
    bool operator()(pair<int, int> &p1, pair<int, int> &p2)
    {
        if (p1.first == p2.first)
            return p1.second < p2.second;

        return p1.first > p2.first;
    }
};

class Solution
{
public:
    vector<int> frequencySort(vector<int> &nums)
    {
        unordered_map<int, int> um;
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> minHeap;

        for (int i = 0; i < nums.size(); i++)
            um[nums[i]]++;

        for (auto i = um.begin(); i != um.end(); i++)
            minHeap.push({i->second, i->first});

        vector<int> ans;
        while (minHeap.size())
        {
            int ele = minHeap.top().second;
            int freq = minHeap.top().first;
            while (freq--)
                ans.push_back(ele);
            minHeap.pop();
        }

        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}