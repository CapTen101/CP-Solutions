#include <bits/stdc++.h>
using namespace std;

#define my_sizeof(type) ((char *)(&type + 1) - (char *)(&type))
#define loop(typeofx, x, start, end) for (typeofx x = start; x < end; ++x)
#define listTraverse(datatypeoflist, x, startList, endList) for (list<datatypeoflist>::iterator x = startList; x != endList; ++x)
#define ll long long int
#define l long int
#define pb push_back

class Solution
{
public:
    int minStartValue(vector<int> &nums)
    {
        int n = nums.size();
        int startvalue = 1, temp = 1;

    startover:

        for (int i = 0; i < n; i++)
        {
            cout << i << "  iteration" << endl;
            temp +=nums[i];
            if (temp < 1)
            {
                startvalue++;
                temp = startvalue;
                goto startover;
            }
        }

        return startvalue;
    }
};

int main()
{
    vector<int> v = {1,-2,-3};
    Solution sol;
    cout << sol.minStartValue(v);
}