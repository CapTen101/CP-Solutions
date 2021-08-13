#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int depth(TreeNode *root)
{
    if (root == NULL)
        return 0;

    return 1 + max(depth(root->right), depth(root->left));
}

bool isBalanced(TreeNode *root)
{
    if (root == NULL)
        return true;
    int gap = depth(root->right) - depth(root->left);
    cout << gap << endl;
    return (abs(gap) == 0 || abs(gap) == 1) and isBalanced(root->right) and isBalanced(root->left);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}