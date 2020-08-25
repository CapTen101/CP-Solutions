#include <iostream>
using namespace std;

int equilibriumPoint(long long a[], int n);

int main()
{

    long long t;
    cin >> t;

    while (t--)
    {
        long long n;
        cin >> n;
        long long a[n];

        for (long long i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        cout << equilibriumPoint(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends

// Function to find equilibrium point
// a: input array
// n: size of array
int equilibriumPoint(long long a[], int n)
{
    long long ls = 0, rs = 0;
    long long sum = 0;

    for (int i = 0; i < n; i++)
        sum += a[i];

    rs = sum;

    for (int i = 0; i < n; i++)
    {
        rs -= a[i];

        if (rs == ls)
            return i + 1;

        ls += a[i];
    }

    return -1;
}