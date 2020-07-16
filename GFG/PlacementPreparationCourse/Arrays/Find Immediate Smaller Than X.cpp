#include <bits/stdc++.h>
using namespace std;

int immediateSmaller(int arr[], int n, int x)
{
    int mindiff, pos;

    mindiff = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        if ((x - arr[i]) <= 0)
            continue;
        else
        {
            mindiff = min(x - arr[i], mindiff);
            if (mindiff == (x - arr[i]))
                pos = i;
        }
    }

    if (mindiff != INT_MAX)
        return arr[pos];

    else
        return -1;
}

int main()
{

    int t;
    cin >> t;

    while (t--)
    {

        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        int x;
        cin >> x;

        cout << immediateSmaller(arr, n, x) << endl;
    }

    return 0;
}