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

void inOrder(TreeNode *root, vector<int> &nodes)
{
    if (root == NULL)
        return;

    inOrder(root->left, nodes);
    nodes.push_back(root->val);
    inOrder(root->right, nodes);
}

int minDiffInBST(TreeNode *root)
{
    if (root == NULL)
        return 0;
    vector<int> nodes;
    inOrder(root, nodes);
    int minDiff = INT_MAX;
    for (int i = 0; i < nodes.size() - 1; i++)
    {
        minDiff = min(minDiff, nodes[i + 1] - nodes[i]);
    }

    return minDiff == INT_MAX ? 0 : minDiff;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}