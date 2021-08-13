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

void helper(TreeNode *root, int level, int &maxLevel, int &value)
{
    if (root == NULL)
        return;

    level++;
    if (level > maxLevel)
    {
        value = root->val;
        maxLevel++;
    }

    helper(root->left, level, maxLevel, value);
    helper(root->right, level, maxLevel, value);
}

int findBottomLeftValue(TreeNode *root)
{
    int value = root->val;
    int maxLevel = 0;
    helper(root, 0, maxLevel, value);
    return value;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}