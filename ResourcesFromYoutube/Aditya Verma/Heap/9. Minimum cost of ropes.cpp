#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    long long minCost(long long arr[], long long n) {
        priority_queue<long long, vector<long long>, greater<long long>> mh; // minHeap
        
        for(long long i=0; i<n; i++){
            mh.push(arr[i]);
        }
        
        long long cost = 0;
        
        while(mh.size()>1){
            long long first = mh.top();
            mh.pop();
            long long second = mh.top();
            mh.pop();
            cost += first + second;
            mh.push(first+second);
        }
        
        return cost;
    }
};

long long minCost(long long arr[], long long n);
int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}
