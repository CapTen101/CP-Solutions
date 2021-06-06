#include <bits/stdc++.h>
using namespace std;

#define my_sizeof(type) ((char *)(&type + 1) - (char *)(&type))
#define FOR(i, start, end) for (int i = start; i < end; i++)
#define ll long long int
#define ull unsigned long long int
#define ul unsigned long int
#define get cin >>
#define print cout <<
#define inarr(s, n, arr)        \
    for (int i = s; i < n; i++) \
        cin >> arr[i];
#define outarr(s, n, arr)       \
    for (int i = s; i < n; i++) \
        cout << arr[i];
#define start \
    int t;    \
    cin >> t; \
    while (t--)

class MyStack
{

    int maxSize;

    long stackArray[];

    int top;

public:
    MyStack(int s)
    {
        maxSize = s;
        stackArray = new long[maxSize];
        top = -1;
    }

    void push(long j)
    {
        stackArray[++top] = j;
    }

    long pop()
    {
        return stackArray[top--];
    }

    long peek()
    {
        return stackArray[top];
    }

    boolean isEmpty()
    {
        return (top == -1);
    }

    boolean isFull()
    {
        return (top == maxSize - 1);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}