#include <bits/stdc++.h>
using namespace std;

int helper_old(int &target, int position, int speed)
{
    if (position == target)
        return 0;

    if (position < target)
    { // before target

        int steps = 0;
        if (speed < 0)
        { // rr -> car is reversed
            steps += 1;
            speed = 1;
        }

        int t = position + speed;

        if (t == target)
        { // uske upar hain
            return 1;
        }
        else if (t < target)
        { // peeche hain
            return 1 + steps + helper_old(target, t, 2 * speed);
        }
        else
        { // paar kar gaye -> min(rr, a)
            return steps + min(2 + helper_old(target, position, 1), 1 + helper_old(target, t, 2 * speed));
        }
    }
    else // beyond target
    {
        int steps = 0;
        if (speed)
        { // rr -> car is reversed
            steps += 1;
            speed = -1;
        }

        int t = position + speed;

        if (t == target)
        { // uske upar hain
            return 1 + steps;
        }
        else if (t > target)
        { // aage hain
            return 1 + steps + helper_old(target, t, 2 * speed);
        }
        else
        { // paar kar gaye -> min(rr, a)
            return min(2 + steps + helper_old(target, position, -1), 1 + steps + helper_old(target, t, 2 * speed));
        }
    }
}

int helper(int &target, int position, int speed)
{
    if (position == target)
        return 0;

    if (position < target)
    { // before target

        int steps = 0;
        if (speed < 0)
        { // rr -> car is reversed
            steps += 1;
            speed = 1;
        }

        int t = position + speed;

        if (t == target)
        { // uske upar hain
            return 1 + steps;
        }
        else if (speed == 1)
        { // peeche hain
            return 1 + steps + helper(target, t, 2 * speed);
        }
        else
        { // paar kar gaye -> min(rr, a)
            return steps + min(2 + helper(target, position, 1), 1 + helper(target, t, 2 * speed));
        }
    }
    else // beyond target
    {
        int steps = 0;
        if (speed > 0)
        { // rr -> car is reversed
            steps += 1;
            speed = -1;
        }

        int t = position + speed;

        if (t == target)
        { // uske upar hain
            return 1 + steps;
        }
        else if (speed == -1)
        { // aage hain
            return 1 + steps + helper(target, t, 2 * speed);
        }
        else
        { // paar kar gaye -> min(rr, a)
            return min(2 + steps + helper(target, position, -1), 1 + steps + helper(target, t, 2 * speed));
        }
    }
}

int racecar(int target)
{
    return helper(target, 0, 1);
}

// int racecar(int target)
// {
//     int dp[target + 1];
//     memset(dp, 1, target + 1);
//     // Arrays.fill(dp, 1, dp.length, -1);
//     return racecar(target, dp);
// }

// int racecar(int i, int dp[])
// {
//     if (dp[i] >= 0)
//     {
//         return dp[i];
//     }

//     dp[i] = INT_MAX;

//     int m = 1, j = 1;

//     for (; j < i; j = (1 << ++m) - 1)
//     {
//         for (int q = 0, p = 0; p < j; p = (1 << ++q) - 1)
//         {
//             dp[i] = min(dp[i], m + 1 + q + 1 + racecar(i - (j - p), dp));
//         }
//     }

//     dp[i] = min(dp[i], m + (i == j ? 0 : 1 + racecar(j - i, dp)));

//     return dp[i];
// }

// int dp[10001];
// int racecar(int t)
// {
//     if (dp[t] > 0)
//         return dp[t];
//     int n = floor(log2(t)) + 1, res;
//     if (1 << n == t + 1)
//         dp[t] = n;
//     else
//     {
//         dp[t] = racecar((1 << n) - 1 - t) + n + 1;
//         for (int m = 0; m < n - 1; ++m)
//             dp[t] = min(dp[t], racecar(t - (1 << (n - 1)) + (1 << m)) + n + m + 1);
//     }
//     return dp[t];
// }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << racecar(5) << endl;
}