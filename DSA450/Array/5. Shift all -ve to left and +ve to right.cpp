#include <bits/stdc++.h>
using namespace std;

void shiftall(int arr[], int n)
{
    int l = 0;
    int r = n - 1;

    while (l <= r)
    {
        if (arr[l] > 0 && arr[r] < 0)
        {
            int temp = arr[l];
            arr[l] = arr[r];
            arr[r] = temp;
            l++;
            r--;
        }

        else if (arr[l] < 0 && arr[r] > 0)
        {
            l++;
            r--;
        }
        else if (arr[l] > 0 && arr[l] > 0)
            r--;
        else if (arr[l] < 0 && arr[r] < 0)
        {
            l++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

int main()
{
    int arr[] = {
        -8,
        9,
        6,
        -11,
        11,
        11,
    };
    int n = sizeof(arr) / sizeof(arr[0]);
    shiftall(arr, n);
}