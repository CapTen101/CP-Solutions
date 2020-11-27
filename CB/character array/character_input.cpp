#include <bits/stdc++.h>
using namespace std;

#define my_sizeof(type) ((char *)(&type + 1) - (char *)(&type))
#define for (i, start, end) for (int i = start; i < end; i++)
#define ll long long int
#define ull unsigned long long int
#define l long int
#define ul unsigned long int
#define start \
    int t;    \
    cin >> t; \
    while (t--)
const ll mod = 1000000007;

// NOTE

// cin.get() gets a single character
// put a loop to read all characters until we get a '\n'
// like depicted in the below function:

void readline(char a[], int maxLen, char DELIM = '\n')
{
    int i = 0;
    char ch = cin.get();

    while (ch != DELIM)
    {
        a[i] = ch;
        i++;
        if (i == maxLen - 1)
        {
            break;
        }
        ch = cin.get();
    }

    a[i] = '\0';
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);

    char a[1000];

    readline(a, 1000);

    // THIS SAME PURPOSE IS FULFILLED BY A FUNCTION CALLED GETLINE!

    char b[1000];
    cin.getline(b, 1000, '$');

    // BOTH DO THE SAME THING EXACTLY!

    cout << a << endl;
}