#include <iostream>
using namespace std;

int kill(int h, int p)
{
    if (h <= 0)
        return 1;
    if (p <= 0)
        return 0;

    h -= p;

    return kill(h, p / 2);
}

int main()
{
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--)
    {
        int h, p;
        cin >> h >> p;
        cout << kill(h, p) << endl;
    }
    return 0;
}
