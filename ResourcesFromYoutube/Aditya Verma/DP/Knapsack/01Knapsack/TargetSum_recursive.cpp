// BEST ARTICLE EXPLAINING ALL APPROACHES:
// https://medium.com/swlh/solving-the-target-sum-problem-with-dynamic-programming-and-more-b76bd2a661f9

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
        cout << arr[i];
#define start \
    int t;    \
    cin >> t; \
    while (t--)

int helperRecursive(vector<int> arr, int index, int target, int sum)
{
    if (index == arr.size())
    {
        return (sum == target ? 1 : 0);
    }

    return helperRecursive(arr, index + 1, target, sum - arr[index]) + helperRecursive(arr, index + 1, target, sum + arr[index]);
}

int findTargetSumWays(vector<int> &arr, int target)
{
    // RECURSIVE

    int total = 0;
    for (int i = 0; i < arr.size(); i++)
        total += arr[i];

    if ((target > total) || (target + total) % 2)
        return 0;

    return helperRecursive(arr, 0, target, 0);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}