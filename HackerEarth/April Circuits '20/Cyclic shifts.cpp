#include <bits/stdc++.h>
using namespace std;

#define my_sizeof(type) ((char *)(&type + 1) - (char *)(&type))
#define loop(typeofx, x, start, end) for (typeofx x = start; x < end; ++x)
#define listTraverse(datatypeoflist, x, startList, endList) for (list<datatypeoflist>::iterator x = startList; x != endList; ++x)
#define ll long long int
#define l long int
#define pb push_back
#define MOD 1000000007

int* decToBinary(int n)
{
	// array to store binary number
	int binaryNum[32];

	// counter for binary array
	int i = 0;
	while (n > 0)
	{

		// storing remainder in binary array
		binaryNum[i] = n % 2;
		n = n / 2;
		i++;
	}

	static int binaryNumber[32];

	for (int j = i - 1; j >= 0; j--)
	{
		binaryNumber[i-1-j]=binaryNum[j];
	}

	return binaryNumber;
}

int main()
{

    int t;
    cin >> t;

    loop(int, i, 0, t)
    {
        char c;
        l N;
        int m;
        cin >> N >> m >> c;
        

        if (c == 'L')
        {

        }
    }
}