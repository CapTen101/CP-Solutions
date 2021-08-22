#include <bits/stdc++.h>
using namespace std;

int maxProduct(vector<int> &nums)
{
    int n = nums.size();

    int overall_max = 1, temp_max = 1;
    for (int i = 0; i < n; i++)
    {
        temp_max *= nums[i];
        if (temp_max > overall_max)
            overall_max = temp_max;
    }

    return overall_max;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}