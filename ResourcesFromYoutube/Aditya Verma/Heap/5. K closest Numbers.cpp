// https://practice.geeksforgeeks.org/problems/k-closest-elements3619/1
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
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        // sorting approach
        /*
        vector<pair<int, int>> temp;
        int n = arr.size();
        for(int i=0; i<n; i++){
            temp.push_back({abs(arr[i] - x), arr[i]});
        }
        
        std::sort(temp.begin(), temp.end());
        
        vector<int> ans;
        for(int i=0; i<k; i++){
            ans.push_back(temp[i].second);
        }
        
        std::sort(ans.begin(), ans.end());
        return ans;
        */

        // Heap approach
        priority_queue<pair<int, int>> maxHeap;
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            maxHeap.push({abs(arr[i] - x), arr[i]});
            if (maxHeap.size() > k)
            {
                maxHeap.pop();
            }
        }

        vector<int> ans;
        while (maxHeap.size())
        {
            ans.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        std::sort(ans.begin(), ans.end());

        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}