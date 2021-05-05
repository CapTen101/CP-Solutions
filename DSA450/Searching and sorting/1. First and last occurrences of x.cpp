// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
vector<int> find(int a[], int n, int x);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int arr[n], i;
        for (i = 0; i < n; i++)
            cin >> arr[i];
        vector<int> ans;
        ans = find(arr, n, x);
        cout << ans[0] << " " << ans[1] << endl;
    }
    return 0;
}

// } Driver Code Ends

vector<int> find(int arr[], int n, int x)
{
    int first = -1;
    int last = -1;

    int l = 0;
    int r = n - 1;

    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
        {
            first = mid;
            r = mid - 1;
            continue;
        }
        else if (x < arr[mid])
        {
            r = mid - 1;
            continue;
        }
        else if (x > arr[mid])
        {
            l = mid + 1;
            continue;
        }
    }

    l = 0;
    r = n - 1;

    while (l <= r)
    {
        int mid1 = l + (r - l) / 2;

        if (arr[mid1] == x)
        {
            last = mid1;
            l = mid1 + 1;
            continue;
        }
        else if (x < arr[mid1])
        {
            r = mid1 - 1;
            continue;
        }
        else if (x > arr[mid1])
        {
            l = mid1 + 1;
            continue;
        }
    }

    vector<int> v(2);
    v[0] = first;
    v[1] = last;

    return v;
}