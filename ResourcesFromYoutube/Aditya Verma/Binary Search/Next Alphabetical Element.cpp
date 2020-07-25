#include <bits/stdc++.h>
using namespace std;

#define start \
    int t;    \
    cin >> t; \
    while (t--)

char search(char arr[], int n, char x)
{
    int l = 0;
    int r = n - 1;
    char res = '#';

    if (arr[l] > x)
        return arr[l];

    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (arr[mid] == x)
        {
            l = mid + 1;
            continue;
        }

        else if (arr[mid] < x)
        {
            l = mid + 1;
            continue;
        }

        else if (arr[mid] > x)
        {
            res = arr[mid];
            r = mid - 1;
        }
    }

    return char(res);
}

int main()
{
    ios_base::sync_with_stdio(false);

    // start
    // {
    //     int n;
    //     char x;
    //     cin >> n >> x;

    //     char arr[n];

    //     for (int i = 0; i < n; i++)
    //     {
    //         cin >> arr[i];
    //     }

    //     cout << search(arr, n, x) << endl;
    // }

    int n = 3;
    char x = 'g';

    char arr[] = {'c', 'f', 'j'};

    cout << search(arr, n, x) << endl;
}