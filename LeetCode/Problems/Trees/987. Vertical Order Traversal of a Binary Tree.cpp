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

vector<vector<int>> verticalTraversal(TreeNode *root)
{
    if (root == NULL)
        return {};

    map<int, vector<int>> m;
    queue<pair<int, TreeNode *>> q;
    q.push({0, root});
    m[0] = {root->val};

    while (q.size())
    {
        TreeNode *curr = q.front().second;
        int curr_level = q.front().first;
        q.pop();

        if (curr->right)
        {
            q.push({curr_level + 1, curr->right});
            m[curr_level + 1].push_back(curr->right->val);
        }
        if (curr->left)
        {
            q.push({curr_level - 1, curr->left});
            m[curr_level - 1].push_back(curr->left->val);
        }
    }

    vector<vector<int>> ans(m.size());
    for (auto i : m)
    {
        vector<int> v = i.second;
        sort(v.begin(), v.end());
        ans.push_back(v);
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}