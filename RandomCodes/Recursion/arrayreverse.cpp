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

int i = 0;
void arrayreverse(int A[], int i, int j)
{
    if (i < j)
    {
        swap(A[i], A[j]);
        i++;
        j--;
        arrayreverse(A, i, j);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    int arr[3] = {1, 2, 3};
    int i = 0;
    int j = 2;

    arrayreverse(arr, 0, 2);

    loop(int, i, 0, 3)
    {
        cout << arr[i];
    }
}