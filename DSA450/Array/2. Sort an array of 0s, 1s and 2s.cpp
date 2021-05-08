// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    void sort012(int a[], int n)
    {
        // coode here
        // int c0=0, c1=0, c2=0;
        // for(int i=0; i<n; i++)
        // {
        //     switch(a[i])
        //     {
        //         case 0:
        //         {
        //             c0++;
        //             break;
        //         }

        //         case 1:
        //         {
        //             c1++;
        //             break;
        //         }

        //         case 2:
        //         {
        //             c2++;
        //             break;
        //         }
        //     }
        // }

        // for(int i=0; i<c0; i++)
        // {
        //     a[i] = 0;
        // }

        // for(int i=c0; i<c1+c0; i++)
        // {
        //     a[i] = 1;
        // }

        // for(int i=c1+c0; i<c0+c1+c2; i++)
        // {
        //     a[i] = 2;
        // }

        //ANOTHER APPROACH
        int l = 0;
        int r = n - 1;
        int it = 0;

        while (it <= r)
        {
            if (a[it] == 0)
            {
                // int temp = a[l];
                // a[l] = a[it];
                // a[it] = temp;
                swap(a[l], a[it]);
                l++;
                it++;
            }
            else if (a[it] == 1)
            {
                it++;
            }
            else if (a[it] == 2)
            {
                // int temp = a[r];
                // a[r] = a[it];
                // a[it] = temp;
                swap(a[r], a[it]);
                r--;
            }
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
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }

        cout << endl;
    }
    return 0;
}

// } Driver Code Ends