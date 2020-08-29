#include <bits/stdc++.h>
using namespace std;

#define start \
    int t;    \
    cin >> t; \
    while (t--)
// vector<string> ans;
vector<string> cap(string op, string ip, vector<string> &ans)
{
    if (ip.empty())
    {
        ans.push_back(op);
        return ans;
    }

    //     string op1 = op;
    //     string op2 = op;

    //     if (ip[0] >= 'a' && ip[0] <= 'z') // if lowercase charcter is there
    //     {
    //         op1.push_back(ip[0]);          // take the lowercase letter
    //         op2.push_back(toupper(ip[0])); // take the uppercase letter
    //         ip.erase(ip.begin() + 0);      // remove that element from the input
    //     }
    //     else if (ip[0] >= 'A' && ip[0] <= 'Z') // if uppercaser letter is there
    //     {
    //         op1.push_back(ip[0]);          // take the uppercase letter
    //         op2.push_back(tolower(ip[0])); // take the lowercase letter
    //         ip.erase(ip.begin() + 0);      // remove that element from the input
    //     }
    //     else // if number is there
    //     {
    //         op1.push_back(ip[0]); // do nothing
    //         op2.push_back(ip[0]); // same, do nothing
    //         ip.erase(ip.begin() + 0);
    //         goto number;
    //     }

    //     cap(op1, ip);
    // number:
    //     cap(op2, ip);

    //     return ans;

    // Above is my way, and
    // below is Aditya's way

    if (isalpha(ip[0]))
    {
        string op1 = op;
        string op2 = op;
        op1.push_back(tolower(ip[0]));
        op2.push_back(toupper(ip[0]));
        ip.erase(ip.begin() + 0);
        cap(op1, ip, ans);
        cap(op2, ip, ans);
    }
    else
    {
        string op1 = op;
        op1.push_back(ip[0]);
        ip.erase(ip.begin() + 0);
        cap(op1, ip, ans);
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    vector<string> ans;
    cap("", "FKqeaCFIESzo", ans);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
}