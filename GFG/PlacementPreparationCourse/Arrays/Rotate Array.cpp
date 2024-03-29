// #include <bits/stdc++.h>
// using namespace std;

// #define my_sizeof(type) ((char *)(&type + 1) - (char *)(&type))
// #define loop(typeofx, x, start, end) for (typeofx x = start; x < end; x++)
// #define ll long long int
// #define ull unsigned long long int
// #define l long int
// #define ul unsigned long int
// #define start \
//     int t;    \
//     cin >> t; \
//     while (t--)
// const ll mod = 1000000007;

// void rotateArr(int arr[], int d, int n)
// {
//     int result[n + d];

//     for (int i = 0; i < n; i++)
//     {
//         result[i] = arr[i];
//         if (i <= d - 1)
//             result[n + i] = result[i];
//     }

//     for (int i = d; i < n + d; i++)
//     {
//         arr[i - d] = result[i];
//     }
// }

// int main()
// {
//     int t;
//     cin >> t;

//     while (t--)
//     {
//         int n, d;
//         cin >> n >> d;

//         int arr[n];

//         for (int i = 0; i < n; i++)
//         {
//             cin >> arr[i];
//         }

//         rotateArr(arr, d, n);

//         for (int i = 0; i < n; i++)
//         {
//             cout << arr[i] << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// } //  Driver Code Ends

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> rotate(vector<int> arr, int n, int d)
{

    vector<int> v;

    for (int i = 0; i < d; i++)
    {
        v.push_back(arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = arr[(i + d) % n];
    }

    for (int i = n - d; i < n; i++)
    {
        arr[i] = v[i - n + d];
    }

    return arr;
}

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n, d;
        cin >> n >> d;
        vector<int> arr(n);

        for (int i = 0; i < n; i++)
            cin >> arr[i];

        vector<int> res;
        res = rotate(arr, n, d);

        for (int i = 0; i < n; i++)
            cout << res[i] << " ";
    }
}