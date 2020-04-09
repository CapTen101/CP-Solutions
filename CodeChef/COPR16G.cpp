#include<bits/stdc++.h>
using namespace std;

#define my_sizeof(type) ((char *)(&type + 1) - (char *)(&type))
#define loop(typeofx, x, start, end) for(typeofx x = start; x < end; ++ x)
#define listTraverse(datatypeoflist, x, startList, endList) for(list<datatypeoflist>::iterator x = startList; x != endList; ++ x)

long long gcd (long long a, long long b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}


int main(){
    long long LCM;
    long t;
    cin>>t;

    loop(long, i, 0, t){
        long long a, b;
        cin>>a>>b;

        LCM = a/gcd(a,b)*b;
        cout<<LCM<<endl;
    }
    
}