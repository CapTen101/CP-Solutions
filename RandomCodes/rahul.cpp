#include <iostream>
using namespace std;
int main()
{
    // int t;
    // cin >> t;
    // for (int u = 1; u <= t; u++)
    // {
    //     int x, n, m;
    //     cin >> x >> n >> m;
    //     bool we;
    //     if (x <= 0)
    //     {
    //         we = true;
    //         goto hello;
    //     }
    //     for (int i = 1; i >= 1; i++)
    //     {

    //         if (x <= 0)
    //         {
    //             we = true;
    //             goto hello;
    //         }
    //         if (n == 0 && m == 0)
    //         {
    //             we = false;
    //             goto hello;
    //         }
    //         if (x > 20)
    //         {
    //             if (n > 0)
    //             {
    //                 x = (x / 2) + 10;
    //                 n--;
    //             }
    //             else if (m > 0)
    //             {
    //                 x = x - 10;
    //                 m--;
    //                 if (x <= 0)
    //                 {
    //                     we = true;
    //                     goto hello;
    //                 }
    //             }
    //         }
    //         else
    //         {
    //             x = x - (m * 10);
    //             if (x <= 0)
    //             {
    //                 we = true;
    //                 goto hello;
    //             }
    //             else
    //             {
    //                 we = false;
    //                 goto hello;
    //             }
    //         }
    //     }

    // hello:

    //     if (we)
    //     {
    //         cout << "YES" << endl;
    //     }
    //     else
    //     {
    //         cout << "NO" << endl;
    //     }
    // }

    int n = 3;
    int *ptr = &n;
    cout << ptr << " " << *ptr << " " << &ptr << " " << *&ptr << endl;
}