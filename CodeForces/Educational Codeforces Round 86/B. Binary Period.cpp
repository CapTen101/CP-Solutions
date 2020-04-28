#include <bits/stdc++.h>
using namespace std;

#define loop(typeofx, x, start, end) for (typeofx x = start; x < end; x++)
#define pb push_back

int main()
{
    

    int T;
    cin >> T;
    

    loop(int, i, 0, T)
    {
        string t;
        cin>>t;
        bool same = true;
        loop(int, i, 0, t.size())
        {
            if (t[i]!=t[0])
            {
                same = false;
            }
        }
        if (same)
        {
            cout << t << "\n";
        }
        else if (t.size() == 2)
            cout << t << "\n";
        else
        {
            string ans;
            loop(int, i, 0, t.size())
            {
                ans.pb('0');
                ans.pb('1');
            }
            cout << ans << "\n";
        }
        t.clear();
    }
}