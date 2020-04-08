#include <bits/stdc++.h>
using namespace std;
#define loop(typeofx, x, start, end) for (typeofx x = start; x < end; ++x)
long long binaryexpo(long long a, int b)
{
    if (b == 0)
        return 1;
    long long res = binaryexpo(a, b / 2);
    if (b % 2)
        return (res * res * a)%10;
    else
        return (res * res)%10;
}

int main()
{   int t;
    cin >> t;
    loop(int, i, 0, t){
        int a; long long b;
        cin >> a >> b; long long res = binaryexpo(a, b); cout<<res<<endl;
    }
}