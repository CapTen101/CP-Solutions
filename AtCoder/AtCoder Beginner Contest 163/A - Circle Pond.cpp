
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int r;
    cin >> r;

    double pi = 3.14159265358979323846;
    cout << setprecision(9) << pi * 2 * r;
}
