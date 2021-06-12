// https://practice.geeksforgeeks.org/problems/nearly-sorted-algorithm/0

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
        cout << arr[i] << " ";
#define start \
    int t;    \
    cin >> t; \
    while (t--)

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    start
    {
        // normal sorting method (0.01 seconds)
        /*
        int n, k;
        cin >> n >> k;
        int arr[n];
        inarr(0, n, arr);

        std::sort(arr, arr + n);
        outarr(0, n, arr);
        cout<<endl;
        */

        // minHeap method: (0.02 seconds)
        int n, k;
        cin >> n >> k;
        int arr[n];
        inarr(0, n, arr);

        int idx = 0;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (int i = 0; i < n; i++)
        {
            minHeap.push(arr[i]);
            if (minHeap.size() > k)
            {
                arr[idx] = minHeap.top();
                minHeap.pop();
                idx++;
            }
        }

        while (minHeap.size())
        {
            arr[idx] = minHeap.top();
            minHeap.pop();
            idx++;
        }

        outarr(0, n, arr);
        cout << endl;
    }
}