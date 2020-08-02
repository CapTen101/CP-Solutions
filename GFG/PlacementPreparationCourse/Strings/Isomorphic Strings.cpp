// { Driver Code Starts
// C++ program to check if two strings are isomorphic
#include <iostream>
#include <string.h>

using namespace std;
#define MAX_CHARS 256

bool areIsomorphic(string, string);

// Driver program
int main()
{
    int t;
    cin >> t;
    string s1, s2;
    while (t--)
    {
        cin >> s1;
        cin >> s2;
        cout << areIsomorphic(s1, s2) << endl;
    }

    return 0;
}

bool areIsomorphic(string str1, string str2)
{
    int n = str1.length();
    int m = str2.length();

    if (n != m)
        return 0;

    int map[MAX_CHARS]; // for visited chars in str1
    memset(map, -1, sizeof(map));

    bool marked[MAX_CHARS] = {0}; // for marking chars in str2

    for (int i = 0; i < n; i++)
    {
        if (map[str1[i]] == -1) // if current char of str1 is not mapped
        {
            if (marked[str2[i]]) // but str2's current char has been visited, then false
                return 0;

            map[str1[i]] = str2[i]; // else map the value and mark the str2's char as marked
            marked[str2[i]] = 1;
        }
        else if (map[str1[i]] != str2[i])
            return 0;
    }

    return 1;
}