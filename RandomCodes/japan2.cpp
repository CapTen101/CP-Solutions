#include <iostream>
#include <string>
using namespace std;

#define WRONG_INPUT 100

long long fact(int n)
{
    // single line to find factorial
    return (n == 1 || n == 0) ? 1 : n * fact(n - 1);
}

// for counting digits
int countDigit(long long n)
{
    int count = 0;
    while (n != 0)
    {
        n = n / 10;
        ++count;
    }
    return count;
}

//program for binomial cofficient
long long int binomialC(int n, int k)
{
    long long int res = 1;

    if (k > n - k)
        k = n - k;

    for (int i = 0; i < k; ++i)
    {
        res *= (n - i);
        res /= (i + 1);
    }

    return res;
}

long long int pattern(int m, int n)
{
    int total = m * n;

    if ((m * n) % 2 != 0)
        return 0;

    // unsigned long long res = fact(m * n) / (fact((m * n) / 2) * fact((m * n) / 2));
    unsigned long long int res = binomialC(total, total / 2);

    if (countDigit(res) == 9)
        return res;

    res = res % 1000000000;

    return res;
}

int main()
{
    int m, n;
    cin >> m >> n;

    if (cin.fail())
    {
        _Exit(100);
    }

    long long int res = pattern(m, n);

    if (res == 0)
    {
        cout << "000000000" << endl;
        return 0;
    }

    if (countDigit(res) < 9)
    {
        int zerocount = 9 - countDigit(res);

        for (int i = 1; i <= zerocount; i++)
            cout << 0;
        cout << res;
    }
    else
    {
        cout << res << endl;
    }
}
