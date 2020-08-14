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

int count1 = 0;

int size(Node *root)
{
    if (root == NULL)
        return;
    else
    {
        return 1 + size(root->right) + size(root->left); // counting the root node as 1 and then checking for left and
        // right sub - tree recursively
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
}