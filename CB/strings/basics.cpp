#include <bits/stdc++.h>
using namespace std;

#define my_sizeof(type) ((char *)(&type + 1) - (char *)(&type))
#define FOR(i, start, end) for (int i = start; i < end; i++)
#define ll long long int
#define ull unsigned long long int
#define l long int
#define ul unsigned long int
#define start \
    int t;    \
    cin >> t; \
    while (t--)
const ll mod = 1000000007;

int main()
{
    ios_base::sync_with_stdio(false);

    // string init
    string s0;
    string s1("Hello World");

    string s2 = "Hello World";

    // copy constructor (copying s2 to s3)
    string s3(s2);
    string s4 = s3;

    // init a string from a char array[]
    char a[] = {'a', 'b', 'c', '\0'};
    string s5(a);

    cout << s0 << endl;
    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;
    cout << s4 << endl;
    cout << s5 << endl;

    // check string to be empty
    if (s0.empty())
        cout << "s0 is empty" << endl;
    ;

    // append characters
    s0.append("I love C++");
    cout << s0 << endl;

    // comparing two strings
    s0 = "Apple";
    s1 = "Mango";

    cout << "comparison results:" << s0.compare(s1) << endl; // compare() returns either 0, > 0, < 0 depending on the lexicographical order of the strings, For equal strings 0 returns

    // Operator Overloading
    if (s1 > s0)
    {
        cout << "Mango string is bigger than Apple string" << endl;
    }

    // find substrings
    string s = "hello how are you";
    int index = s.find("are");

    cout << "index is" << index << endl;

    // Remove a word from the string
    string word = " are";
    int len = word.length();
    // starting from index 'index' remove 'len' number of characters
    s.erase(index, len);
    cout << s << endl;

    // iterators:
    for (auto it = s1.begin(); it != s1.end(); it++)
    {
        cout << (*it) << endl;
    }

}