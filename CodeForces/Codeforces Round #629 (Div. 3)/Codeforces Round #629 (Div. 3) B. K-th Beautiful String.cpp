// link: https://codeforces.com/contest/1328


#include<iostream>
using namespace std;
int main(){
	long t;
	long long n,k;
	
	for(long i=0; i<t; ++i){
		cin>>n,k;
		printstring(n,k);
	}
	
}

string printstring(long long n, long long k){
	
	string s;
	
	for(long i=0; i<n; ++i){
		if(i==(n-1)){
			s[n-1]="b";
		}else if(i==(n-2)){
			s[n-2]="b";
		}else{
			s[i]="a";
		}
	}
	
	for(long i=0; i<(n-1); ++i){
		s[n-2-i]="b";
		cout<<s<<endl;
		s[n-2-i]="a";
	}
}
