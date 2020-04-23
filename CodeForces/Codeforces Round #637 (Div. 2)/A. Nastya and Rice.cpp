#include <bits/stdc++.h>
using namespace std;

#define my_sizeof(type) ((char *)(&type + 1) - (char *)(&type))
#define loop(typeofx, x, start, end) for (typeofx x = start; x < end; x++)
#define listTraverse(datatypeoflist, x, startList, endList) for (list<datatypeoflist>::iterator x = startList; x != endList; ++x)
#define ll long long int
#define l long int
#define pb push_back
#define MOD 1000000007

// int main()
// {
//     int t;
//     cin >> t;

//     while (t--)
//     {
//         int n, a, b, c, d;
//         cin >> n >> a >> b >> c >> d;

//         // if (((a + b) * n > (c + d)) || ((a + b) * n < (c - d)) || ((a - b) * n > (c + d)) || ((a - b) * n < (c - d)))
//         // if ((((a + b) * n) > (c - d)) && (((a + b) * n) < (c + d)))
//         // {
//         //     cout << "Yes" << endl;
//         // }
//         // else if ((((a - b) * n) < (c + d)) && (((a - b) * n) > (c - d)))
//         // {
//         //     cout << "Yes" << endl;
//         // }
//         // else if ((((a - b) * n) > (c + d)) || (((a - b) * n) < (c - d)))
//         // {
//         //     cout << "No" << endl;
//         // }
//         // else if (((a + b) * n) < (c - d))
//         // {
//         //     cout << "No" << endl;
//         // }
//         if ((((a - b) * n) > (c - d)) && (((a + b) * n) < (c + d)))
//         {
//             // if (((a + b) * n) > (c + d))
//             // {
//             //     if (((a - b) * n) < (c - d))
//             //     {
//             cout << "Yes" << endl;
//             //     }
//             //     else
//             //     {
//             //         cout << "Yes" << endl;
//             //     }
//             // }
//             // if (((a - b) * n) < (c - d))
//             // {
//             //     cout << "No" << endl;
//             // }
//         }
//         else
//         {
//             cout << "No" << endl;
//         }

//         // loop(int, i, c - d, c + d + 1)
//         // {
//         //     if ((i > (a - b) * n) && (i < (a + b) * n))
//         //     {
//         //         cout << "Yes" << endl;
//         //     }
//         //     else
//         //     {
//         //         cout << "No" << endl;
//         //     }
//         // }
//     }
// }

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, a, b, c, d;
        cin >> n >> a >> b >> c >> d;
        int start1 = (a - b) * n;
        int end1 = (a + b) * n;
        int start2 = c - d;
        int end2 = c + d;
        bool we = false;
        if (start2 >= (a - b) * n && start2 <= (a + b) * n)
        {
            we = true;
        }
        else if (end2 >= (a - b) * n && end2 <= (a + b) * n)
        {
            we = true;
        }
        else if (start2 < (a - b) * n && end2 > (a + b) * n)
        {
            we = true;
        }
        else
        {
            we = false;
        }
        if (we)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
}