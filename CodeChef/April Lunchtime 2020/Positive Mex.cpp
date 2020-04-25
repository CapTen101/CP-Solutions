#include <bits/stdc++.h>
using namespace std;

#define my_sizeof(type) ((char *)(&type + 1) - (char *)(&type))
#define loop(typeofx, x, start, end) for (typeofx x = start; x < end; x++)
#define listTraverse(datatypeoflist, x, startList, endList) for (list<datatypeoflist>::iterator x = startList; x != endList; ++x)
#define ll long long int
// #define l long int
#define pb push_back
#define MOD 998244353

vector<int> printSubsequences(vector<int> arr, int index, vector<int> subarr)
{
    // Print the subsequence when reach
    // the leaf of recursion tree
    if (index == arr.size())
    {
        int l = subarr.size();

        // Condition to avoid printing
        // empty subsequence
        if (l != 0)
            return subarr;
    }
    else
    {
        // Subsequence without including
        // the element at current index
        printSubsequences(arr, index + 1, subarr);

        subarr.push_back(arr[index]);

        // Subsequence including the element
        // at current index
        printSubsequences(arr, index + 1, subarr);
    }
    return;
}

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        vector<ll> a(n);
        loop(int, i, 0, n)
        {
            cin >> a[i];
        }

        
    }
}