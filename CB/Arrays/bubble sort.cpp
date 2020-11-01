#include <bits/stdc++.h>
using namespace std;

// n-1 elements need n-1 iterations for moving n-1 elements  to the end
void bubble(int a[], int n)
{
    // pairwise swapping of the elements is done:
    // i corrsponds to the number of iterations
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
        }
    }

    for (int i = 0; i < n; i++)
        cout << a[i] << endl;
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

    bubble(arr, n);
}