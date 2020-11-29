// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//User function template for C++

class Solution
{
public:
    int middle(int A, int B, int C)
    {

        // return (A>B)?(A>C?(B>C?B:C):A):(A>C?A:C);
        int ab = A - B;
        int bc = B - C;
        int ca = C - A;

        if (ab >= 0)
        {
            if (bc >= 0)
                return B;
            else
            {
                if (ca >= 0)
                    return A;
                else
                    return C;
            }
        }
        else
        {
            if (bc >= 0)
            {
                if (ca >= 0)
                    return C;
                else
                    return A;
            }
            else
                return B;
        }
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int A, B, C;
        cin >> A >> B >> C;
        Solution ob;
        cout << ob.middle(A, B, C) << "\n";
    }
    return 0;
} // } Driver Code Ends