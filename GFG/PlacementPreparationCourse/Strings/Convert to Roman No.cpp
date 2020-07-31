#include <bits/stdc++.h>
using namespace std;

string convertToRoman(int);

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;

        cout << convertToRoman(N);
        cout << endl;
    }
    return 0;
} // } Driver Code Ends

/*you are required to complete 
this function*/

// n :given number that you are require to convert
string convertToRoman(int n)
{
    //Your code here
    int r, q;

    string roman;

    if (n >= 1000)
    {
        r = n % 1000;
        q = n / 1000;

        while (q--)
            roman.append("M");
        n = r;
    }

    if (n >= 900)
    {
        r = n % 900;
        q = n / 900;

        while (q--)
            roman.append("CM");
        n = r;
    }

    if (n >= 500)
    {
        r = n % 500;
        q = n / 500;

        while (q--)
            roman.append("D");

        n = r;
    }

    if (n >= 400)
    {
        r = n % 400;
        q = n / 400;

        while (q--)
            roman.append("CD");
        n = r;
    }

    if (n >= 100)
    {
        r = n % 100;
        q = n / 100;

        while (q--)
            roman.append("C");

        n = r;
    }

    if (n >= 90)
    {
        r = n % 90;
        q = n / 90;

        while (q--)
            roman.append("XC");
        n = r;
    }

    if (n >= 50)
    {
        r = n % 50;
        q = n / 50;

        while (q--)
            roman.append("L");

        n = r;
    }

    if (n >= 40)
    {
        r = n % 40;
        q = n / 40;

        while (q--)
            roman.append("XL");
        n = r;
    }

    if (n >= 10)
    {
        r = n % 10;
        q = n / 10;

        while (q--)
            roman.append("X");

        n = r;
    }

    if (n >= 9)
    {
        r = n % 9;
        q = n / 9;

        while (q--)
            roman.append("IX");
        n = r;
    }

    if (n >= 5)
    {
        r = n % 5;
        q = n / 5;

        while (q--)
            roman.append("V");
        n = r;
    }

    if (n >= 4)
    {
        r = n % 4;
        q = n / 4;

        while (q--)
            roman.append("IV");
        n = r;
    }

    if (n >= 1)
    {
        r = n % 1;
        q = n / 1;

        while (q--)
            roman.append("I");
        n = r;
    }

    return roman;
}