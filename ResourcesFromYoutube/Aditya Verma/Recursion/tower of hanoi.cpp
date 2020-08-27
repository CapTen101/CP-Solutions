#include <bits/stdc++.h>
using namespace std;

#define start \
    int t;    \
    cin >> t; \
    while (t--)

void tower(int n, int s, int d, int h, int &count)
{
    count++;
    //base condition
    if (n == 1)
    {
        cout << "move disk " << n << " from rod " << s << " to rod " << d << endl;
        return;
    }

    // hypothesis and induction combined:
    tower(n - 1, s, h, d, count);                                              // move all top n-1 plates to helper tower. Hence for this operation, helper tower is our destination.
    cout << "move disk " << n << " from rod " << s << " to rod " << d << endl; // moving that last plate from source to destination tower.

    // now moving all remaining n-1 plates from helper tower to ultimate destiantion tower:
    tower(n - 1, h, d, s, count);

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);

    int count = 0;
    tower(3, 1, 3, 2, count);
    cout << "the number of steps are: " << count << endl;
}