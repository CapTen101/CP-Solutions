// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution
{
public:
    vector<int> kLargest(int arr[], int n, int k)
    {
        // sorting technique:
        /*
	    std::sort(arr, arr+n);
	    vector<int> ans;
	    for(int i=n-1, m=1; i>=0 && m<=k; i--, m++){
	        ans.push_back(arr[i]);
	    }
	    
	    return ans;
	    */

        // maxHeap technique
        /*
	    vector<int> ans;
        priority_queue<int> maxHeap;
        for (int i = 0; i < n; i++)
        {
            maxHeap.push(arr[i]);
            if (maxHeap.size() > k)
                maxHeap.pop();
        }

        for (int i = 0; i < k; i++)
        {
            ans.push_back(maxHeap.top());
            maxHeap.pop();
        }

        return ans;
        */

        //minHeap technique
        vector<int> ans;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (int i = 0; i < n; i++)
        {
            minHeap.push(arr[i]);
            if (minHeap.size() > k)
            {
                minHeap.pop();
            }
        }

        while (minHeap.size() > 0)
        {
            ans.push_back(minHeap.top());
            minHeap.pop();
        }

        for (int i = 0; i < k / 2; i++)
        {
            swap(ans[i], ans[k - i - 1]);
        }

        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.kLargest(arr, n, k);
        for (auto x : ans)
        {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends