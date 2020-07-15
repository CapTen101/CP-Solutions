#include <bits/stdc++.h>
using namespace std;

// Function to find the subarray with given sum k
// arr: input array
// n: size of array
void subarraySum(int arr[], int n, int s)
{
    int left = 0, right = 0;
    int sum = 0;
    sum += arr[left];
    for (int i = 0; i < n; i++)
    {
        if (sum < s)
        {
            right++;
            sum += arr[right];
            continue;
        }
        else if (sum > s)
        {
            sum -= arr[left];
            left++;
            continue;
        }
        else if (sum == s)
        {
            cout << left + 1 << " " << right + 1;
            return;
        }
    }

    cout << -1;
    return;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        long long s;
        cin >> n >> s;
        int arr[n];

        for (int i = 0; i < n; i++)
            cin >> arr[i];

        subarraySum(arr, n, s);
        cout << endl;
    }
    return 0;
}