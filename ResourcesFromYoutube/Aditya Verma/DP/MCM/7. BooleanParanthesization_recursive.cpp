#include <bits/stdc++.h>
using namespace std;

// here we need isTrue also since we need sub-expressions to evaluate to either true of false
// only the ultimate expression must be true
int solve(string s, int i, int j, bool isTrue)
{
    // no element
    if (i > j)
        return 0;

    // if single element is there
    if (i == j)
    {
        // if we need the expression to be true then check the single element
        if (isTrue)
            // if true, then return true
            return int(s[i] == 'T');
        else
            // if false, then return false
            return int(s[i] == 'F');
    }

    // BASE CONDITION OVER....

    // here, i and j will be on 'T' or 'F' in the string
    // here, k will be on operators so that brackets can be placed from i->k-1 and k+1->j
    // and hence, k+=2 will be there since k moves from operator to operator
    // calculate all leftTrue, leftFalse, rightTrue, rightFalse
    int ans = 0;
    for (int k = i + 1; k < j; k += 2)
    {
        int lt = solve(s, i, k - 1, true);
        int lf = solve(s, i, k - 1, false);
        int rt = solve(s, k + 1, j, true);
        int rf = solve(s, k + 1, j, false);

        // if the expression needs to be evaluated to true
        // choose all values which eval the expression to true
        if (isTrue)
        {
            if (s[k] == '^') // XOR
            {
                ans += (lt * rf + lf * rt);
            }
            else if (s[k] == '&') // AND
            {
                ans += (lt * rt);
            }
            else // OR
            {
                ans += (lt * rf + lf * rt + lt * rt);
            }
        }
        // else if the expression needs to be evaluated to false
        // choose all values which evaluate expression to false
        else
        {
            if (s[k] == '^') // XOR
            {
                ans += (lt * rt + lf * rf);
            }
            else if (s[k] == '&') // AND
            {
                ans += (lf * rf + lf * rt + lt * rf);
            }
            else // OR
            {
                ans += (lf * rf);
            }
        }
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}