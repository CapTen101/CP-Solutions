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

bool subsetsum(int arr[], int size, int sum)
{
    if (sum == 0)
        return true;
    if (size == 0 && size != 0)
        return false;

    if (arr[size - 1] <= sum)
        return (subsetsum(arr, size - 1, sum - arr[size - 1]) || subsetsum(arr, size - 1, sum));
    else
        return subsetsum(arr, size - 1, sum);
}

int main()
{
    ios_base::sync_with_stdio(false);

    int arr[2] = {1, 2};
    int sum = 10;
    bool ans = subsetsum(arr, 2, sum);

    if (ans)
        cout << "true" << endl;
    else
        cout << "false" << endl;
}