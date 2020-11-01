#include <bits/stdc++.h>
using namespace std;
#define start \
    int t;    \
    cin >> t; \
    while (t--)

void selection_sort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_index = i;

        for (int j = i; j < n; j++)
        {
            if (a[j] < a[min_index])
                min_index = j;
        }

        swap(a[i], a[min_index]);
    }

    //print the sorted array

    cout << "Sorting..." << endl;

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    selection_sort(arr, n);
}