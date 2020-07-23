#include <iostream>
using namespace std;

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

int main()
{
    //code
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;

    while (t--)
    {
        int N, k;
        cin >> N >> k;
        int a[N];

        for (int i = 0; i < N; i++)
            cin >> a[i];

        int found = bin_search_ITERATIVE(a, 0, N - 1, k);

        if (found != -1)
            cout << 1 << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}