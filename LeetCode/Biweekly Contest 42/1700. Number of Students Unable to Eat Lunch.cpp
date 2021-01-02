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
    int countStudents(vector<int> &students, vector<int> &sandwiches)
    {
        int n = students.size();
        int not_int = 0; // students not-interested

        int st_one = 0, st_zero = 0;

        for (auto i : students)
        {
            if (i)
                st_one++;
            else
                st_zero++;
        }

        for (auto i : sandwiches)
        {
            if (i && st_one)
                st_one--;

            else if (!i && st_zero)
                st_zero--;

            else
                break;
        }

        if (st_one)
            return st_one;
        else if (st_zero)
            return st_zero;
        else
            return 0;

        return not_int;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    Solution obj;
    vector<int> v1 = {1, 1, 1, 0, 0, 1};
    vector<int> v2 = {1, 0, 0, 0, 1, 1};

    cout << obj.countStudents(v1, v2) << endl;
}