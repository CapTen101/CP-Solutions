// { Driver Code Starts
#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

void reverseWords(char *);

/* Driver function to test above functions */
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        char s[10000];
        cin >> s;
        reverseWords(s);
        cout << endl;
    }
} // } Driver Code Ends

#define DELIM "."

void reverseWords(char *s)
{
    int n = strlen(s);

    string ans; // rev is the reverse string of s character array

    char *ptr = strtok(s, DELIM);

    vector<string> v;

    while (ptr != NULL)
    {
        v.push_back(ptr);
        ptr = strtok(NULL, DELIM);
    }

    for (int i = v.size() - 1; i >= 0; i--)
    {
        cout << v[i];
        if (i != 0)
            cout << ".";
    }
}
