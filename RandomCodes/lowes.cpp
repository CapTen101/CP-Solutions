#include <bits/stdc++.h>
using namespace std;

char *merge(char *s1, char *s2)
{
    int n1 = strlen(s1);
    int n2 = strlen(s2);
    int total = n1 + n2;

    if (n1 == 0)
    {
        if (n2 == 0)
            return NULL;
        else
            return s2;
    }
    else if (n2 == 0)
        return s1;

    int less = min(n1, n2);
    int big = max(n1, n2);

    char *ans = new char[total + 1];
    // string ans(total, '!');

    for (int i = 0; i < less; i++)
    {
        if (s1[i] <= s2[i])
        {
            ans[i] = s1[i];
            ans[total - i - 1] = s2[i];
        }
        else
        {
            ans[i] = s2[i];
            ans[total - i - 1] = s1[i];
        }
    }

    if (n1 != n2)
    {
        if (n1 < n2)
        {
            for (int i = less; i < big; i++)
                ans[i] = s2[i];
        }
        else
        {
            for (int i = less; i < big; i++)
                ans[i] = s1[i];
        }
    }

    ans[total] = '\0';

    char *ans_ptr = ans;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char first[] = "are";
    char second[] = "denim";

    cout << merge(first, second);
}