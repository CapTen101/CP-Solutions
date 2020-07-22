#include <bits/stdc++.h>
using namespace std;

#define my_sizeof(type) ((char *)(&type + 1) - (char *)(&type))
#define loop(typeofx, x, start, end) for (typeofx x = start; x < end; x++)
#define ll long long int
#define ull unsigned long long int
#define l long int
#define ul unsigned long int
#define start \
    int t;    \
    cin >> t; \
    while (t--)
const ll mod = 1000000007;

int countdiff(int arr[], int size, int diff)
{
    int range = 0;
    loop(int, i, 0, size) range += arr[i];
    int sum = (diff + range) / 2;

    int t[size + 1][sum + 1];

    loop(int, i, 0, size + 1)
    {
        loop(int, j, 0, sum + 1)
        {
            if (j == 0)
                t[i][j] = 0;
            if (i == 0)
                t[i][j] = 1;
        }
    }

    loop(int, i, 1, size + 1)
    {
        loop(int, j, 1, sum + 1)
        {
            if (arr[i - 1] <= j)
                t[i][j] = t[i - 1][j - arr[i - 1]] + t[i - 1][j];
            else
                t[i][j] = t[i - 1][j];
        }
    }

    return t[size][sum];
}

int main()
{
    ios_base::sync_with_stdio(false);

    int arr[4] = {1, 1, 2, 3};

    cout << countdiff(arr, 4, 1) << endl;
}