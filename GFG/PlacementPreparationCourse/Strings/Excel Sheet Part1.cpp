#include <bits/stdc++.h>
using namespace std;

string ExcelColumn(int n)
{
    string s;
    int i = 0;

    while (n)
    {
        int r = n % 26;

        if (r == 0)
        {
            s.push_back('Z');
            n /= 26;
            n--;
        }
        else
        {
            s.push_back('A' + r - 1);
            n /= 26;
        }
    }

    reverse(s.begin(), s.end());

    return s;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << ExcelColumn(n) << endl;
    }
    return 0;
}