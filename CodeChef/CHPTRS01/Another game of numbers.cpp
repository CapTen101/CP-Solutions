#include <iostream>
#include <bits/stdc++.h>
using namespace std;
# define my_sizeof(type) ((char *)(&type+1)-(char*)(&type))
//int size = sizeof(arr)/sizeof(arr[0]);

int* decToBinary(int n) 
{ 
    // array to store binary number 
    static int binaryNum[32]; 
  
    // counter for binary array 
    int i = 0; 
    while (n > 0) { 
  
        // storing remainder in binary array 
        binaryNum[i] = n % 2; 
        n = n / 2; 
        i++; 
    } 
  
   static int binaryCorrect[32];
    // printing binary array in reverse order 
    for (int j = i - 1; j >= 0; j--) {
        binaryCorrect[i-1-j]=binaryNum[j];
} 

return binaryCorrect;
}

int main() {
	int n;
	cin>>n;
	int* binary = decToBinary(n);
	int size = sizeof(binary)/sizeof(binary[0]);
	cout<<binary[3]<<endl;
//	int m=my_sizeof(binary)/my_sizeof(binary[0]);
	cout<<"Size is "<<size;
}
