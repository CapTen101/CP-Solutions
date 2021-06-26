#include<bits/stdc++.h>
using namespace std;

#define my_sizeof(type) ((char *)(&type + 1) - (char *)(&type))
#define loop(typeofx, x, start, end) for(typeofx x = start; x < end; ++ x)
#define listTraverse(datatypeoflist, x, startList, endList) for(list<datatypeoflist>::iterator x = startList; x != endList; ++ x)
#define ll long long int 
#define l long int
#define pb push_back


int main(){
    
    int t;
    cin>>t;

    loop(int, i, 0, t){
        ll a,b,c,d;
        cin>>a>>b>>c>>d;

        ll x,y,z;

        x=b;
        y=c;
        z=c;

        cout<<x<<" "<<y<<" "<<z<<endl;
    }

}