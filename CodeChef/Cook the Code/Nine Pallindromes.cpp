#include <bits/stdc++.h>
using namespace std;

#define my_sizeof(type) ((char *)(&type + 1) - (char *)(&type))
#define loop(typeofx, x, start, end) for (typeofx x = start; x < end; ++x)
#define listTraverse(datatypeoflist, x, startList, endList) for (list<datatypeoflist>::iterator x = startList; x != endList; ++x)
#define ll long long int
#define ull unsigned long long int
#define l long int
#define pb push_back

bool palindrome(ll num)
{
    ll rev = 0, val;
    val = num;
    while (num > 0)
    {
        rev = rev * 10 + num % 10;
        num = num / 10;
    }
    if (val == rev)
        return true;
    else
        return false;
}

int main()
{
    int t;
    cin >> t;
    ll M = 1000000007;

    loop(int, i, 0, t)
    {
        l n;
        bool palin, notzero;
        cin >> n;
        ll sum = 0;
        ll number = pow(10, n) - 1;
        for (ll i = number; i > number / 10; i -= 9)
        {

            palin = palindrome(i);
            notzero = i % 10 ? true : false;
            if (palin && notzero)
            {
                sum+=i;
                
            }
        }
        cout << sum%M <<endl;
    }
}