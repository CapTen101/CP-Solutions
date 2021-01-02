#include <bits/stdc++.h>
using namespace std;

#define my_sizeof(type) ((char *)(&type + 1) - (char *)(&type))
#define FOR(i, start, end) for (int i = start; i < end; i++)
#define ll long long int
#define ull unsigned long long int
#define l long int
#define ul unsigned long int
#define start \
    int t;    \
    cin >> t; \
    while (t--)

class Solution
{
public:
    bool canFormArray(vector<int> &arr, vector<vector<int>> &p)
    {
        unordered_map<int, int> mp;

        int element = -1;

        for (int i = 0; i < p.size(); i++)
            mp[p[i][0]] = i;

        for (int i = 0; i < arr.size();)
        {
            element = arr[i];
            cout << element << endl;
            if (mp.find(element) == mp.end()) // if not found
            {
                cout << "mp[element] index: " << mp[element] << endl;
                return false;
            }

            for (int j = 0; j < p[mp[element]].size(); j++)
            {
                if (arr[i++] != p[mp[element]][j])
                    return false;
            }
        }

        return true;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
}