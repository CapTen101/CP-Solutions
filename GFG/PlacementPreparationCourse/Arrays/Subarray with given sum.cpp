#include <bits/stdc++.h>
using namespace std;

void subarraySum(int arr[], int n, long long s)
{
    int left = 0, right = 0;
    long long sum = 0;

    do
    {
        if (left == 0)
            sum += arr[0];

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
        if (sum == s)
        {
            cout << left + 1 << " " << right + 1;
            return;
        }
    } while (left <= right && left < n && right < n);

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