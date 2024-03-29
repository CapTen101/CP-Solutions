#include <bits/stdc++.h>
using namespace std;

vector<int> help_classmate(vector<int> a, int n)
{
    // code here
    stack<int> s;
    vector<int> res(n, -1);

    for (int i = 0; i < a.size(); i++)
    {
        // push the index into stack instead of the array elements (BRILLIANT!)
        while (s.empty() == false && a[s.top()] > a[i])
        {
            res[s.top()] = a[i];
            s.pop();
        }
        s.push(i);
    }

    return res;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> array(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> array[i];
        }
        vector<int> result = help_classmate(array, n);
        for (int i = 0; i < n; ++i)
        {
            cout << result[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}