#include<bits/stdc++.h>
using namespace std;

long long int helper(int &n, int &m, int i, int j)
{
    if(i<=0 || j<=0 || i>n || j>n)
        return INT_MAX;

    if(i==n && j==m)
        return 0;

    return 1 + min(helper(n,m,i+j, j), helper(n,m,i,i+j));
}

int minSteps(int input1, int input2)
{
    int n = input1;
    int m = input2;

    long long int ans = helper(n,m,1,1);
    
    return (int) (ans == INT_MAX ? -1 : ans);
}

int main()
{
    cout<<minSteps(3,2)<<endl;
    return 0;
}