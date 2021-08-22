#include <bits/stdc++.h>
using namespace std;

vector<int> productExceptSelf(vector<int> &nums)
{
    int n = nums.size();
    vector<int> answer(n);

    //left-side products
    int left = 1;
    answer[0] = left;
    for (int i = 1; i < n; i++)
    {
        left *= nums[i - 1];
        answer[i] = left;
    }

    // right-side products
    int right = 1;
    for (int i = n - 2; i >= 0; i--)
    {
        right *= nums[i + 1];
        answer[i] *= right;
    }

    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}