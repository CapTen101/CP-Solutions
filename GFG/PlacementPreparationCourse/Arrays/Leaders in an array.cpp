#include <bits/stdc++.h>
using namespace std;

// Function to find the leaders in an array of size n
vector<int> leader(int arr[], int n)
{
    int maxnum = arr[n - 1];
    int temp = maxnum;

    vector<int> leader;
    leader.push_back(arr[n - 1]);

    for (int i = n - 1; i >= 0; i--)
    {
        if (temp > maxnum)
        {
            maxnum = temp;
            leader.push_back(maxnum);
        }
        temp = max(arr[i], temp);
    }
}

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;

        int a[n];

        for (long long i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        vector<int> v = leader(a, n);

        for (auto it = v.begin(); it != v.end(); it++)
        {
            cout << *it << " ";
        }

        cout << endl;
    }
}