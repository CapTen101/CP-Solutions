#include <bits/stdc++.h>
using namespace std;

vector<int> reversearray(vector<int> v)
{
    for (int i = 0; i < v.size() / 2; i++)
    {
        swap(v[i], v[v.size() - 1 - i]);
    }

    return v;
}

// Function to find the leaders in an array of size n
vector<int> leader(int arr[], int n)
{
    int maxnum = arr[n - 1];

    vector<int> leader;
    leader.push_back(arr[n - 1]);

    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] >= maxnum)
        {
            maxnum = arr[i];
            leader.push_back(maxnum);
        }
    }

    vector<int> result = reversearray(leader);
    return result;
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