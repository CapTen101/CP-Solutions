#include <bits/stdc++.h>
using namespace std;

#define my_sizeof(type) ((char *)(&type + 1) - (char *)(&type))
#define loop(typeofx, x, start, end) for (typeofx x = start; x < end; ++x)
#define listTraverse(datatypeoflist, x, startList, endList) for (list<datatypeoflist>::iterator x = startList; x != endList; ++x)
#define vectorTraverse(datatypeofvector, x, startVector, endVector) for (vector<datatypeofvector>::iterator x = startVector; x != endVector; x++)

void showVector(vector<long long> g)
{
    vector<long long>::iterator it;
    cout << endl;
    for (it = g.begin(); it != g.end(); ++it)
        cout << *it;
}

vector<long long> convertDecimalToBinary(long n, vector<long long> binarynumber)
{
    long long binaryNumber = 0;
    int remainder, i = 1;

    while (n != 0)
    {
        remainder = n % 2;
        binarynumber.push_back(remainder);
        n /= 2;
        binaryNumber += remainder * i;
        i *= 10;
    }

    return binarynumber;
}

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        long A, B;
        cin >> A >> B;

        vector<long long> a, b;

        a = convertDecimalToBinary(A, a);
        b = convertDecimalToBinary(B, b);

        showVector(a);
        showVector(b);
        vector<long long>::iterator k;

        long long start = b[0];
        long long end = b.back();
        b.front() = end;

        loop(int, i, 1, a.size()){
            
        };
    }
}
