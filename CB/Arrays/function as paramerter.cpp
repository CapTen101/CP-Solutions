#include <bits/stdc++.h>
using namespace std;

// comparator for the STL Sort() function:
bool compare(int a, int b)
{
    return a > b;
}

// using the STL Sort function:
void SortArrayUsingSTL(int arr[], int n)
{
    sort(arr, arr + n);
}

// sorting in decreasing order using the comparator function
void decSort(int arr[], int n)
{
    sort(arr, arr + n, compare);
}

// Passing function as a parameter in C++ ---> Will do the same here as decSort()
void decSortFunctionParameter(int arr[], int n, bool (&cmp)(int a, int b))
{
    // passing the cmp() parameter to the sort function.
    sort(arr, arr + n, cmp);
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

    SortArrayUsingSTL(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    decSortFunctionParameter(arr, n, compare);

    cout << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}