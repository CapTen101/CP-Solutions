#include <bits/stdc++.h>
using namespace std;

#define my_sizeof(type) ((char *)(&type + 1) - (char *)(&type))
#define loop(typeofx, x, start, end) for (typeofx x = start; x < end; ++x)
#define listTraverse(datatypeoflist, x, startList, endList) for (list<datatypeoflist>::iterator x = startList; x != endList; ++x)

long long gcd(long a, long b)
{
    return b ? gcd(b, a % b) : a;
}

int main(){
    int t;
    cin >> t;

    loop(int, i, 0, t){
        int n; cin >> n; long a[n];
        loop(int, j, 0, n){
            cin >> a[j];
        }

        long long GCD[n - 1];
        long long max;

        loop(int, k, 0, n - 2)
        {
            GCD[k] = gcd(a[k], a[k + 1]);
            if ((k > 0) && (GCD[k] > GCD[k - 1])){
                max = GCD[k];
            }
        }
        cout << max<<endl;
    }
}