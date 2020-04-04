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

void shift(vector<long long> g)
{
    long long end = g.back();
    for (int i = g.size() - 1; i > 0; i--)
    {
        g[i] = g[i - 1];
    }
    g.front() = end;
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

string vectorToString(vector<long long> vec)
{
    ostringstream vts;
    if (!vec.empty())
    {
        // Convert all but the last element to avoid a trailing ","
        copy(vec.begin(), vec.end() - 1, ostream_iterator<int>(vts));

        // Now add the last element with no delimiter
        vts << vec.back();
    }
    return vts.str();
}

int stringToInteger(string s)
{
    stringstream geek(s);

    int x;
    geek >> x;
    return x;
}

int binaryToDecimal(int n) 
{ 
    int num = n; 
    int dec_value = 0; 
  
    // Initializing base value to 1, i.e 2^0 
    int base = 1; 
  
    int temp = num; 
    while (temp) { 
        int last_digit = temp % 10; 
        temp = temp / 10; 
  
        dec_value += last_digit * base; 
  
        base = base * 2; 
    } 
  
    return dec_value; 
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

        int xordone = A ^ B;
        int countofshift = 0;

        loop(int, i, 0, b.size())
        {
            shift(b);
            countofshift++;
            string bstr = vectorToString(b);
            int bp = stringToInteger(bstr);
            int bnew = binaryToDecimal(bp);
            int anotherxor = A ^ bnew;

            if (anotherxor > xordone)
            {
                xordone = anotherxor;
                continue;
            }
            else
            {
                cout << countofshift << " " << anotherxor;
            }
        }
    }
}
