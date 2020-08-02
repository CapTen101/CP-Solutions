// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int isValid(char *);
int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        char s[10000];
        cin >> s;
        cout << isValid(s) << endl;
    }
    return 0;
} // } Driver Code Ends

#define delim "."

bool checktoken(char *c)
{
    int n = strlen(c);
    if (n > 3 || n == 0) // if it's bigger than 3 digits, then false;
        return false;

    for (int i = 0; i < n; i++)
        if ((c[i] >= '0' && c[i] <= '9') == false)
            return false;

    string s(c);

    if (s.find('0') == 0 && n > 1) // it shouldn't contain like 005 or 04, so false;
        return false;

    int snum = stoi(s);

    if (snum > 255 || snum < 0) // should be in the range 0 & 255;
        return false;

    return true;
}

int isValid(char *ip)
{
    if (ip == NULL)
        return 0;

    int dots = 0, count = 0;
    int n = strlen(ip);

    for (int i = 0; i < n; i++)
    {
        if (ip[i] == '.')
            count++;
    }

    if (count != 3)
        return 0;

    char *ptr = strtok(ip, delim);

    if (ptr == NULL)
        return 0;

    while (ptr)
    {
        if (checktoken(ptr))
        {
            ptr = strtok(NULL, delim);
            if (ptr != NULL)
                dots++;
        }

        else
            return 0;
    }

    if (dots != 3)
        return 0;

    return 1;
}