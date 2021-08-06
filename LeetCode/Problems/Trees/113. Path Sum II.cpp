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
    if (!node->left and !node->right)
        return true;
    else
        return false;
}

void dfs(TreeNode *root, int targetSum, vector<int> &path, vector<vector<int>> &paths, int sumTillCurrNode)
{
    if (!root)
        return;

    path.push_back(root->val);
    sumTillCurrNode += root->val;
    if (sumTillCurrNode == targetSum and isLeaf(root))
        paths.push_back(path);

    dfs(root->right, targetSum, path, paths, sumTillCurrNode);
    dfs(root->left, targetSum, path, paths, sumTillCurrNode);

    path.pop_back();
}

vector<vector<int>> pathSum(TreeNode *root, int targetSum)
{
    vector<vector<int>> paths;
    vector<int> path;
    dfs(root, targetSum, path, paths, 0);

    return paths;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}