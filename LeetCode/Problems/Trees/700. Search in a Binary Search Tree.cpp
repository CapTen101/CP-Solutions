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

TreeNode *searchBST(TreeNode *root, int &val)
{
    if (root == NULL)
        return NULL;

    if (root->val == val)
        return root;

    TreeNode *left = searchBST(root->left, val);
    if (left)
        return left;
    TreeNode *right = searchBST(root->right, val);
    if (right)
        return right;

    return NULL;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}