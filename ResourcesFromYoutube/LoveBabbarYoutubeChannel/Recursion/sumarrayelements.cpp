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

int sum = 0;
int i = 0;
int sumarray(int A[], int size)
{
    if (i == size)
        return 0;
    sum = A[i++] + sumarray(A, size);
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int arr[3] = {1, 2, 3};
    cout << sumarray(arr, 3);
}