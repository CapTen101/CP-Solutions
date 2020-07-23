/*
Problem Statement: https://www.geeksforgeeks.org/find-rotation-count-rotated-sorted-array/


no. of time sorted array is rotated is "index of the smallest element" {CLOCKWISE ROATION}
no. of time sorted array is rotated is "(length of array - index of minimum element) % length of array" {ANTI-CLOCKWISE ROATION}

*/

// below is for clockwise rotation:
// #include <bits/stdc++.h>
// using namespace std;

// #define start \
//     int t;    \
//     cin >> t; \
//     while (t--)

// int bin(int arr[], int n)
// {
//     int l = 0, r = n - 1;

//     while (l <= r)
//     {
//         if (arr[l] < arr[r])
//         {
//             return l;
//         }

//         int mid = l + (r - l) / 2;

//         int next = (mid + 1) % n;
//         int prev = (mid + n - 1) % n;

//         if (arr[mid] >= arr[l])
//         {

//             if (arr[mid] > arr[next])

//                 return arr[next];

//             l = mid + 1;
//         }
//         else
//         {

//             if (arr[mid] < arr[prev])

//                 return arr[mid];

//             r = mid;
//         }
//     }

//     return arr[l];
// }

// int main()
// {
//     ios_base::sync_with_stdio(false);

//     start
//     {
//         int n;
//         cin >> n;
//         int arr[n];

//         for (int i = 0; i < n; i++)
//         {
//             cin >> arr[i];
//         }

//         cout << bin(arr, n) << endl;
//     }
// }

/*
ACCEPTED SOLUTION
*/

#include <bits/stdc++.h>
using namespace std;
int pivotind(long long int arr[], long int st, long int end, long int n)
{
    if (n == 1)
        return 0;
    if (n == 2)
    {
        if (arr[0] > arr[1])
            return 1;
        else
            return 0;
    }

    for (long i = 0; i < n; i++)
    {
        if (arr[0] < arr[n - 1])
            return 0;
        if (i > 0 && arr[i] <= arr[(i + 1) % n] && arr[i] < arr[i - 1])
            return i;
    }

    return -1;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long int n;
        cin >> n;
        long long int a[n];
        for (long i = 0; i < n; i++)
            cin >> a[i];
        cout << pivotind(a, 0, n - 1, n) << endl;
    }
    return 0;
}