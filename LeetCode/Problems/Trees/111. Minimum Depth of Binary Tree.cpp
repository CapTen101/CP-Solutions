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

int helper(TreeNode *root)
{
    if (root == NULL)
        return 0;

    if (!root->right and !root->left)
        return 1;

    return 1 + min(helper(root->left), helper(root->right));
}

int minDepth(TreeNode *root)
{
    if (root == NULL)
        return 0;

    if (root->right and root->left)
        return 1 + min(minDepth(root->left), minDepth(root->right));
    else if (root->right)
        return 1 + minDepth(root->right);
    else if (root->left)
        return 1 + minDepth(root->left);
    else
        return 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}