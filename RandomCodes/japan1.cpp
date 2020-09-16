#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// Using manachar's algorithm to find the longest palindrome
// LPS - Longest Palindromic Subsequence
void PalindromicString(char *str)
{
    int N = strlen(str);

    if (N == 0)
        return;

    // Position count
    N = 2 * N + 1;

    //LPS Length Array
    int L[N];
    L[0] = 0;
    L[1] = 1;

    int C = 1, R = 2, i = 0;
    int isymmetric;
    int maximum_LPS_length = 0;
    int maximum_LPS_centerPosition = 0;
    int start = -1, end = -1, diff = -1;

    for (i = 2; i < N; i++)
    {
        //get currentLeftPosition isymmetric for currentRightPosition i
        isymmetric = 2 * C - i;
        L[i] = 0;
        diff = R - i;

        //If currentRightPosition i is within centerRightPosition R
        if (diff > 0)
            L[i] = min(L[isymmetric], diff);

        while (((i + L[i]) < N && (i - L[i]) > 0) &&
               (((i + L[i] + 1) % 2 == 0) ||
                (str[(i + L[i] + 1) / 2] == str[(i - L[i] - 1) / 2])))
            L[i]++;

        // Track maximum_LPS_length
        if (L[i] > maximum_LPS_length)
        {
            maximum_LPS_length = L[i];
            maximum_LPS_centerPosition = i;
        }

        if ((i + L[i]) > R)
        {
            C = i;
            R = i + L[i];
        }
    }

    start = (maximum_LPS_centerPosition - maximum_LPS_length) / 2;
    end = start + maximum_LPS_length - 1;

    // using scanf and printf and char[] decreases the time complexity
    for (i = start; i <= end; i++)
        printf("%c", str[i]);

    printf("\n");
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    cin >> line;

    char ch[1000000];

    //converting to char array
    strcpy(ch, line.c_str());

    // print the palindrome here
    PalindromicString(ch);

    cout << endl;

    return 0;
}
