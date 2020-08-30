#include <bits/stdc++.h>
using namespace std;

#define start \
    int t;    \
    cin >> t; \
    while (t--)

int kill(int index, int k, vector<int> &circle)
{
    if (circle.size() == 1)
        return circle[0];

    index = (index + k) % circle.size();
    circle.erase(circle.begin() + index);

    return kill(index, k, circle);
}

int main()
{
    ios_base::sync_with_stdio(false);
    start
    {
        int n, k;
        cin >> n;
        cin >> k;
        k--;
        int index = 0;

        vector<int> circle(n);
        for (int i = 0; i < circle.size(); i++)
            circle[i] = i + 1;

        cout << kill(index, k, circle) << endl;
    }
}