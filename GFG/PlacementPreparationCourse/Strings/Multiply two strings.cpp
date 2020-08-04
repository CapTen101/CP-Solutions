// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string multiplyStrings(string, string);

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        string a;
        string b;
        cin >> a >> b;

        cout << multiplyStrings(a, b) << endl;
    }

} // } Driver Code Ends

/*You are required to complete below function */
string multiplyStrings(string s1, string s2)
{
    //Your code here
    string res;
    int n1 = s1.length();
    int n2 = s2.length();

    if (s1 == "0" || s2 == "0")
        return "0";

    if (s1[0] == '-' || s2[0] == '-')
    {
        if (s1[0] == '-' && s2[0] == '-')
        {
            n1--;
            n2--;
            s1 = s1.substr(1);
            s2 = s2.substr(1);
        }
        else if (s1[0] == '-' && s2[0] != '-')
        {
            res.append(1, '-');
            n1--;
            s1 = s1.substr(1);
        }
        else if (s1[0] != '-' && s2[0] == '-')
        {
            res.append(1, '-');
            n2--;
            s2 = s2.substr(1);
        }
    }

    int val[n1 + n2];
    memset(val, 0, sizeof(val));

    for (int i = n1 - 1; i >= 0; i--)
    {
        for (int j = n2 - 1; j >= 0; j--)
        {
            int mul = (s1[i] - '0') * (s2[j] - '0');
            int sum = mul + val[i + j + 1];
            val[i + j] += sum / 10;    // carry value
            val[i + j + 1] = sum % 10; // value to be summed up - without carry
        }
    }

    for (int v : val)
    {
        if (v == 0)
        {
            if (res.length() == 0)
                continue;
            else if (res.length() == 1 && res[0] == '-')
                continue;
            else if (res[0] == '-' && res.length() > 1)
                res.append(to_string(v));
            else if (res.length() != 0)
                res.append(to_string(v));
        }
        else
        {
            res.append(to_string(v));
        }
    }

    return res;
}