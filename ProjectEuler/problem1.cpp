#include<bits/stdc++.h>
using namespace std;

#define my_sizeof(type) ((char *)(&type + 1) - (char *)(&type))
#define loop(typeofx, x, start, end) for(typeofx x = start; x < end; ++ x)
#define listTraverse(datatypeoflist, x, startList, endList) for(list<datatypeoflist>::iterator x = startList; x != endList; ++ x)
#define ll long long int 
#define l long int
#define pb push_back
#define MOD 1000000007


int main(){

    int n = 1000;
    l sum=0;

    loop(int, i, 1, 1000){
        if(i%3==0 || i%5==0){
            sum+=i;
        }
    }

    cout<<sum;
    
}