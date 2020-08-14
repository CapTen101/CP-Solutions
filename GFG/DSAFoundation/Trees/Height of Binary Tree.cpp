#include <bits/stdc++.h>
using namespace std;

#define start \
    int t;    \
    cin >> t; \
    while (t--)

struct Node
{
    int data;
    Node *right;
    Node *left;
};

int ht(Node *root)
{
    if (root == NULL)
        return 0;

    return 1 + max(ht(root->left), ht(root->right));
}

int main()
{
    ios_base::sync_with_stdio(false);
}