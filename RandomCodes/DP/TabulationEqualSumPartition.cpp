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

bool t[6][11];
bool subsetsum(int arr[], int n, int sum)
{
    loop(int, i, 0, n + 1)
    {
        loop(int, j, 0, sum + 1)
        {
            if (i == 0)
                t[i][j] = false;
            if (j == 0)
                t[i][j] = true;
        }
    }

    loop(int, i, 1, n + 1)
    {
        loop(int, j, 1, sum + 1)
        {
            if (arr[i - 1] <= sum)
                t[i][j] = (t[i - 1][j - arr[i - 1]]) || (t[i - 1][j]);
            else
                t[i][j] = t[i - 1][j];
        }
    }

    return t[n][sum];
}

bool equalsumpartition(int arr[], int n)
{
    int totalsum = 0;
    loop(int, i, 0, n) totalsum += arr[i];
    int halfsum = totalsum / 2;
    if (totalsum % 2 != 0)
        return false;
    else
        return subsetsum(arr, n, halfsum);
}

int main()
{
    ios_base::sync_with_stdio(false);

    int arr[5] = {1, 2, 0, 3, 100};
    int sum = 10;
    bool ans = equalsumpartition(arr, 5);

    if (ans)
        cout << "true" << endl;
    else
        cout << "false" << endl;
}