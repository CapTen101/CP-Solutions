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

void bfs(TreeNode *root, vector<int> &nodes, int &maxLevel, int level)
{
    if (root == NULL)
        return;

    level++;
    if (level > maxLevel)
    {
        nodes.push_back(root->val);
        maxLevel++;
    }

    bfs(root->right, nodes, maxLevel, level);
    bfs(root->left, nodes, maxLevel, level);
}

vector<int> rightSideView(TreeNode *root)
{
    vector<int> rightVisibleNodes;
    int maxLevel = 0;
    bfs(root, rightVisibleNodes, maxLevel, 0);
    return rightVisibleNodes;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}