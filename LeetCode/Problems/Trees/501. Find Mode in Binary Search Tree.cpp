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

void preOrder(TreeNode *root, unordered_map<int, int> &um)
{
    if (root == NULL)
        return;

    um[root->val]++;

    preOrder(root->left, um);
    preOrder(root->right, um);
}
vector<int> findMode(TreeNode *root)
{
    unordered_map<int, int> freq;
    preOrder(root, freq);
    int maxFreq = 0;
    int maxElement;
    vector<int> ans;

    for (auto i : freq)
    {
        maxFreq = max(maxFreq, i.second);
        if (maxFreq == i.second)
            maxElement = i.first;
    }

    for (auto i : freq)
    {
        if (i.second == maxFreq)
            ans.push_back(i.first);
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}