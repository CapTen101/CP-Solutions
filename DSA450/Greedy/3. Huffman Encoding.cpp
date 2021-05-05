#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> huffmanCodes(string s, vector<int> f, int N)
    {
        map<char, int> sf;
        for (int i = 0; i < s.size(); i++)
        {
            sf[s[i]] = f[i];
        }

        sort(f.begin(), f.end());
    }
};

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string S;
        cin >> S;
        int N = S.length();
        vector<int> f(N);
        for (int i = 0; i < N; i++)
        {
            cin >> f[i];
        }
        Solution ob;
        vector<string> ans = ob.huffmanCodes(S, f, N);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}