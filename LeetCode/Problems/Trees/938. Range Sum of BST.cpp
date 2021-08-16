#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int rangeSumBST(TreeNode *root, int &low, int &high)
{
    if (root == NULL)
        return 0;

    if (root->val >= low and root->val <= high)
        return root->val + rangeSumBST(root->right, low, high) + rangeSumBST(root->left, low, high);
    else
        return rangeSumBST(root->right, low, high) + rangeSumBST(root->left, low, high);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}