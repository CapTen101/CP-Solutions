// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

char getMaxOccuringChar(char *);

int main()
{

    char str[100];
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%s", str);
        cout << getMaxOccuringChar(str) << endl;
    }
} // } Driver Code Ends

// Function to get maximum occuring
// character in given string str
char getMaxOccuringChar(char *str)
{
    // Your code here
    int n = strlen(str);
    int max = 0;
    char result;

    int count[256] = {0};

    for (int i = 0; i < n; i++)
    {
        count[str[i]]++;
        if (max < count[str[i]])
        {
            max = count[str[i]];
            result = str[i];
        }
    }

    return result;
}
