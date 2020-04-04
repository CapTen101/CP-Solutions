#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; bool A,B;
	cin>>t;
	
	for (int i = 0; i < t; i++) {
	    long n; cin>>n;
	    long long int a[n], b[n];
	    
	    for (long i = 0; i < n; i++) {
	        /* code */
	        cin>>a[i];
	    }
	    
	    for (long i = 0; i < n; i++) {
	        /* code */
	        cin>>b[i];
	    }
	    
	  for (long i = 0; i < n; i++) {
	      for(long j=0; j<n; j++){
	          /* code */
	         if(a[i]>b[j]){
	            A=1;
	         }else{
	             A=0;
	             break;
	         }
	      }
	  }
	  
	  for (long i = 0; i < n; i++) {
	      for(long j=0; j<n; j++){
	          /* code */
	         if(b[i]>a[j]){
	            B=1;
	         }else{
	             B=0;
	             break;
	         }
	      }
	  }
	  
	  if((A==0&&B==0)||(A==1&&B==1)){
	      cout<<"NO";
	  } else{
	      cout<<"YES";
	  }
	    
	}
	return 0;
}

