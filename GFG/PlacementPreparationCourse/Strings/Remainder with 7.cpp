// { Driver Code Starts
#include <iostream>
using namespace std;
int remainderWith7(string);

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        string n;
        cin >> n;

        cout << remainderWith7(n) << endl;
    }
    return 0;
} // } Driver Code Ends

/*You are required to complete this method */
int remainderWith7(string s)
{
    //Your code here

    int arr[6] = {1, 3, 2, -1, -3, -2};
    int arrindex = 0;

    int r = 0;

    for (int i = s.length() - 1; i >= 0; i--)
    {
        r += ((s[i] - '0') * (arr[arrindex % 6])) % 7;
        arrindex++;
        r %= 7;
    }

    if (r < 0)
    {
        r += 7;
        r %= 7;
    }

    return r;
}