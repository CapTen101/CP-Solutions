#include <bits/stdc++.h>
using namespace std;

#define FOR(i, start, end) for (int i = start; i < end; i++)

int main()
{
    int n;
    cin >> n;

    int arr[n];

    // KADANE'S ALGO
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int maxsum = INT_MIN;
    int currentsum = 0;

    for (int i = 0; i < n; i++)
    {
        currentsum = currentsum + arr[i];

        if (currentsum < 0)
            currentsum = 0;

        maxsum = max(maxsum, currentsum);
    }

    cout << maxsum << endl;
}