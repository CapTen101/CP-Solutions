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

bool t[6][12];
bool subsetsum(int arr[], int size, int sum)
{
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
            if (arr[i - 1] <= sum)
                t[i][j] = (t[i - 1][j - arr[i - 1]]) || (t[i - 1][j]);

            else
                t[i][j] = t[i - 1][j];
        }
    }

    return t[size][sum];
}

int main()
{
    ios_base::sync_with_stdio(false);

    int arr[5] = {2, 3, 7, 8, 11};
    int sum = 11;
    bool ans = subsetsum(arr, 5, sum);
    if (ans)
        cout << "true" << endl;
    else
        cout << "false" << endl;
}