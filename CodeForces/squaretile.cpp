#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int n,m,a,nlength,nheight;
    cin>>n>>m>>a;
    double length, height; 
    length = n/a;
    height = m/a;
    cout<<length;
    nlength = ceil(n/a);
    nheight = ceil(m/a);   
    
    cout<<nlength;
    cout<<(nlength*nheight);
}    
    