#include <bits/stdc++.h>
using namespace std;

#define my_sizeof(type) ((char *)(&type + 1) - (char *)(&type))
#define FOR(i, start, end) for (int i = start; i < end; i++)
#define ll long long int
#define ull unsigned long long int
#define l long int
#define ul unsigned long int
#define start \
    int t;    \
    cin >> t; \
    while (t--)
const ll mod = 1000000007;

int main()
{
    ios_base::sync_with_stdio(false);

    char input[] = "Hello World!Second hello world!third hello world";

    // this maintains an internal variable to check for the first token and to then move forward to subsequent tokens.
    char *ptr = strtok(input, "!");
    cout << ptr << endl;

    // due to the above reason, NULL is passed here
    ptr = strtok(NULL, "!");
    cout << ptr << endl;

    ptr = strtok(NULL, "!");
    cout << ptr << endl;

    cout << endl;

    // now doing it through a loop
    char *ptr1 = strtok(input, "!");
    while (ptr1 != NULL)
    {
        cout << ptr1 << endl;
        ptr1 = strtok(NULL, "!");
    }

    // ONLY 1 VARIABLE WORKS FOR A GIVEN CHAR*[] AT A TIME.
    // ABOVE ptr & ptr1 won't work at the same time.
    // hence comment one of these while working with another.

    return 0;
}