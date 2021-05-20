#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string FirstNonRepeating(string a)
    {
        string ans = "";
        char nr = '0';
        int nr_idx = -1;
        unordered_set<char> s;
        vector<char> v;
        for (int i = 0; i < a.length(); i++)
        {
            if (s.find(a[i]) == s.end())
            { // if not found
                if (nr == '0' || nr == '#')
                {
                    nr = a[i];
                    ans += nr;
                    s.insert(a[i]);
                    v.push_back(a[i]);
                    nr_idx++;
                }
                else
                {
                    ans += nr;
                    s.insert(a[i]);
                    v.push_back(a[i]);
                }
            }
            else
            { // if found
                // remove this element a[i] from vector since this is not an eligible nr character
                int remove_idx = -1;
                // get the index where that element is stored in vector
                for (int k = 0; k < v.size(); k++)
                {
                    if (v[k] == a[i])
                    {
                        // cout << v[k] << " ";
                        remove_idx = k;
                        break;
                    }
                }
                // remove that element
                for (int k = remove_idx; k < v.size(); k++)
                {
                    if (k == v.size() - 1)
                    {
                        v.pop_back();
                        break;
                    }
                    v[k] = v[k + 1];
                }

                if (nr == a[i])
                {
                    if (nr_idx > s.size() - 1)
                        nr = '#';
                    else
                    {
                        // nr_idx++;
                        nr = v[nr_idx];
                    }
                    ans += nr;
                }
                else
                {
                    ans += nr;
                    continue;
                }
            }
        }

        return ans;
    }
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        string A;
        cin >> A;
        Solution obj;
        string ans = obj.FirstNonRepeating(A);
        cout << ans << "\n";
    }
    return 0;
}