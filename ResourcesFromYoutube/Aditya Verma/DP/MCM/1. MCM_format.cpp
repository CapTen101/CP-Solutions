#include <bits/stdc++.h>
using namespace std;

int some_function(int x, int y)
{
}

int ans;

int solve(int arr[], int i, int j)
{
    // base condition - think of the first invalid input
    // i==j -> smallest valid input - a single element
    // thus, i>j -> first invalid input -> our base condition
    // THIS MAY BE DIFFERENT DEPENDING ON THE QUESTION, but the format remains same
    if (i > j)
        return 0;

    // not k goes form i -> j
    for (int k = i; k <= j; k++)
    {
        // calc temp answers
        // all data types/limits/conditions maybe different, again depends on question
        // but format is same
        // then do apply some funciton on the temp ans to get final ans
        int temp_ans = solve(arr, i, k) + solve(arr, k + 1, j);
        ans = some_function(temp_ans, ans);
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}