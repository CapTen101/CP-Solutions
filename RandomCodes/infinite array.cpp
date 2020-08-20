#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int k = 1;

    string num = "";

    while (num.length() <= n)
    {
        string test = to_string(k);
        num.append(test);
        k++;
    }

    cout << num[n - 1];
}