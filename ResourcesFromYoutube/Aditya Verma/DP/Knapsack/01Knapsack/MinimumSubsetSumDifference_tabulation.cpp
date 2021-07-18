#include <bits/stdc++.h>
using namespace std;

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

/*
- we'll calc the range in which s1 and s2 exists which is -> (0 to total_arr_sum)
- now s2 = s-s1 where s is the total_arr_sum.
- also s1 goes to only half of this above range since for every present s1 we have (range-s1) present.
- thus use subset sum problem to find for which sum (sum goes haf range: from 0 to total_sum/2) there exists a subset and then find minimum of range-2*s1 for every such s1 present (corresponding to every sum).
*/

int subsetsum(int arr[], int size, int sum)
{
    vector<int> vans;
    bool t[size + 1][sum + 1];

    loop(int, i, 0, size + 1)
    {
        loop(int, j, 0, sum + 1)
        {
            if (i == 0)
                t[i][j] = false;
            if (j == 0)
                t[i][j] = true;
        }
    }

    loop(int, i, 1, size + 1)
    {
        loop(int, j, 1, sum + 1)
        {
            if (arr[i - 1] <= j)
                t[i][j] = (t[i - 1][j - arr[i - 1]]) || (t[i - 1][j]);
            else
                t[i][j] = t[i - 1][j];
        }
    }

    for (int i = 0; i <= sum / 2; i++)
    {
        if (t[size][i])
            vans.push_back(i);
    }

    int mn = INT_MAX;
    for (int i = 0; i < vans.size(); i++)
    {
        mn = min(mn, sum - (2 * vans[i]));
    }
    return mn;
}

int MinSubsetDiff(int arr[], int n)
{
    int range = 0;
    loop(int, i, 0, n) range += arr[i];
    return subsetsum(arr, n, range);
}

int main()
{
    ios_base::sync_with_stdio(false);
    start
    {
        int n;
        cin >> n;
        int arr[n];

        loop(int, i, 0, n) cin >> arr[i];

        cout << MinSubsetDiff(arr, n) << endl;
    }
}