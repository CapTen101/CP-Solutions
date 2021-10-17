#include <bits/stdc++.h>
using namespace std;

// This gives TLE:
int check(string s, int n)
{
    int curr=0;
    for(int i=0; i<s.size(); i++)
    {
        curr=curr*10 + (s[i]-'0');
        curr=curr%n;
    }

    return curr;
}

string multiple(int n) {
    queue<string> q;
    q.push("1");
    set<int> rem;

    while(q.size())
    {
        string s = q.front();
        q.pop();
        int remainder = check(s, n);
        if(remainder==0)
            return s;
        
        // OPTIMIZATION :: only add string in queue IF it's remainder hasn't been occured before 
        if(rem.find(remainder) == rem.end())
        {
            rem.insert(remainder);
            q.push(s+'0');
            q.push(s+'1');
        }
    }
}

// Best approach
string multiple2(int n)
{
    if(n==1)
        return "1";

    queue<int> q;
    q.push(1); // remainder for string -> "1"

    // this vector stores the minimum length number(in string form) which gives remainder i at ith index
    // thus index =0 string is our actual answer
    vector<char> rem(n, '2'); // remainder from 0->n-1 and we want to find least number with remainder = 0
    vector<int> parent(n, -1); // initially no parent so -1
    rem[1] = '1';

    while(q.size())
    {
        int remainder = q.front();
        q.pop();
        if(remainder == 0)
            break;

        int r0 = (remainder*10 + 0)%n;
        int r1 = (remainder*10 + 1)%n;

        if(rem[r0] == '2')
        {
            rem[r0] = '0';
            parent[r0] = remainder;
            q.push(r0);
        }
        if(rem[r1] == '2')
        {
            rem[r1] = '1';
            parent[r1] = remainder;
            q.push(r1);
        }
        
    }
    

    return rem[0];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}