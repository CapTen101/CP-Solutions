#include <bits/stdc++.h>
using namespace std;

// #define my_sizeof(type) ((char *)(&type + 1) - (char *)(&type))
// #define loop(typeofx, x, start, end) for (typeofx x = start; x < end; x++)
// #define ll long long int
// #define ull unsigned long long int
// #define l long int
// #define ul unsigned long int
#define start \
    int t;    \
    cin >> t; \
    while (t--)
// const ll mod = 1000000007;

struct Node
{
    int data;
    Node *left = NULL;
    Node *right = NULL;
};

int print(Node *root)
{
    if (root->left == NULL && root->right == NULL) // this is the base condition
        return 0;

    int left = print(root->left);   // these two steps are part of hypothesis
    int right = print(root->right); // hypothesis

    return 1 + max(left, right); // this is induction!
    // that's it!
}

int main()
{
    ios_base::sync_with_stdio(false);
}