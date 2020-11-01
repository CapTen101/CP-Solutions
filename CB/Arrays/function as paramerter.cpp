#include <bits/stdc++.h>
using namespace std;

// comparator for the STL Sort() function:
bool compare(int a, int b)
{
    return a > b;
}

void SortArrayUsingSTL(int arr[], int n)
{
    // using the STL Sort function:
    sort(arr, arr + n);

    // sorting in decreasing order using the comparator function
    sort(a, a + n, compare);
}

int main()
{
    ios_base::sync_with_stdio(false);
}