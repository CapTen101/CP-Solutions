#include <bits/stdc++.h>
using namespace std;

#define FOR(i, start, end) for (int i = start; i < end; i++)

int main()
{
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int maxsum = 0;
    int currentsum = 0;

    vector<int> prefixArray(n, 0);

    for (int i = 0; i < n; i++)
    {
        prefixArray[i] = prefixArray[i - 1] + arr[i];
    }

    FOR(i, 0, n)
    {
    }
}