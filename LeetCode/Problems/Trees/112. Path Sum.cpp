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

bool isLeaf(TreeNode *node)
{
    if (!node->right and !node->left)
        return true;
    else
        return false;
}

bool helper(TreeNode *root, int t, int sum)
{
    if (root == NULL)
        return false;

    int currSum = sum + root->val;
    if (t == currSum and isLeaf(root))
        return true;

    return (helper(root->left, t, currSum) || helper(root->right, t, currSum));
}

bool hasPathSum(TreeNode *root, int t)
{
    return helper(root, t, 0);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}