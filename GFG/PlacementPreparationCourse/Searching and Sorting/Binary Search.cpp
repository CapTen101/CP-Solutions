// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int bin_search_ITERATIVE(int A[], int left, int right, int k);

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int N;
        cin >> N;
        int a[N];
        for (int i = 0; i < N; i++)
            cin >> a[i];
        int key;
        cin >> key;
        int found = bin_search_ITERATIVE(a, 0, N - 1, key);
        cout << found << endl;
    }
}
// } Driver Code Ends

/*You need to complete this function (RECURSIVE IMPLEMENTATION)*/

int bin_search_RECURSIVE(int A[], int left, int right, int k)
{
    if (left > right)
    {
        return -1;
    }

    int mid = left + (right - left) / 2;

    if (k == A[mid])
        return mid;

    else if (k > A[mid])
    {
        return (bin_search_RECURSIVE(A, mid + 1, right, k));
    }

    else if (k < A[mid])
    {
        return (bin_search_RECURSIVE(A, left, mid - 1, k));
    }
}

/*You need to complete this function (ITERATIVE IMPLEMENTATION)*/

int bin_search_ITERATIVE(int A[], int left, int right, int k)
{
    int n = right + 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (A[mid] == k)
        {
            return mid;
        }

        else if (k > A[mid])
        {
            left = mid + 1;
        }

        else if (k < A[mid])
        {
            right = mid - 1;
        }
    }

    return -1;
}