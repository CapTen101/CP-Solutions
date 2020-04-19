#include <iostream>
using namespace std;

int main()
{
    long n;
    cin >> n;

    long a[n];
    long sub[n];
    sub[0] = 0;

    for (long i = 1; i < n; i++)
    {
        cin >> a[i];
        sub[i] = 0;
    }

    for (long i = 1; i < n; i++)
    {
        sub[a[i] - 1]++;
    }

    for (long i = 0; i < n; i++)
    {
        cout << sub[i] << endl;
    }
}
