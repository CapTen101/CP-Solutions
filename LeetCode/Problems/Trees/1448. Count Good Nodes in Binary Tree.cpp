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

int dfs(TreeNode *root, int maxVal)
{
    if (!root)
        return 0;

    if (root->val < maxVal)
    {
        return dfs(root->left, maxVal) + dfs(root->right, maxVal);
    }
    else
    {
        maxVal = root->val;
        return 1 + dfs(root->left, maxVal) + dfs(root->right, maxVal);
    }
}

int goodNodes(TreeNode *root)
{
    int count = 0;
    int maxVal = root->val;

    return dfs(root, maxVal);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}