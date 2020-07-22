#include <bits/stdc++.h>
using namespace std;

#define my_sizeof(type) ((char *)(&type + 1) - (char *)(&type))
#define loop(typeofx, x, start, end) for (typeofx x = start; x < end; x++)
#define listTraverse(datatypeoflist, x, startList, endList) for (list<datatypeoflist>::iterator x = startList; x != endList; ++x)
#define ll long long int
#define ull unsigned long long int
#define l long int
#define ul unsigned long int
#define start \
    int t;    \
    cin >> t; \
    while (t--)
const ll mod = 1000000007;

bool t[3][11];
bool subsetsumMemoization(int arr[], int size, int sum)
{
    if (sum == 0)
        return true;
    if (size == 0 && sum != 0)
        return false;

    if (t[size][sum] != -1)
    {
        return t[size][sum];
    }

    if (arr[size - 1] <= sum)
        return t[size][sum] = (subsetsumMemoization(arr, size - 1, sum - arr[size - 1]) || subsetsumMemoization(arr, size - 1, sum));
    else
        return t[size][sum] = subsetsumMemoization(arr, size - 1, sum);
}

int main()
{
    ios_base::sync_with_stdio(false);

    memset(t, 1, sizeof(t));

    int arr[5] = {1, 2, 8, 3, 10};
    int sum = 10;
    bool ans = subsetsumMemoization(arr, 5, sum);

    if (ans)
        cout << "true" << endl;
    else
        cout << "false" << endl;
}