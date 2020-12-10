#include <bits/stdc++.h>
using namespace std;

#define my_sizeof(type) ((char *)(&type + 1) - (char *)(&type))
#define FOR(i, start, end) for (int i = start; i < end; i++)
#define ll long long int
#define ull unsigned long long int
#define l long int
#define ul unsigned long int
#define start \
    int t;    \
    cin >> t; \
    while (t--)
const ll mod = 1000000007;

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

class Solution
{
public:
    vector<int> list;

    void *inorder(TreeNode *root)
    {
        if (root == NULL)
            return root;

        inorder(root->left);
        list.push_back(root->val);
        inorder(root->right);
    }

    TreeNode *increasingBST(TreeNode *root)
    {
        // TreeNode *current_node = root;
        // TreeNode *newTreeRoot = new TreeNode();
        // TreeNode *current_new_node = new TreeNode();
        // current_new_node = newTreeRoot;
        // stack<TreeNode *> s;

        // while (current_node != NULL || s.empty() == false)
        // {
        //     s.push(current_node);
        //     current_node = current_node->left; // go all the way to left bottom.
        // }

        // current_node = s.top();
        // newTreeRoot->val = current_node->val;
        // s.pop();

        TreeNode *current = root;
        inorder(root);

        reverse(list.begin(), list.end());
        int index = list.size() - 1;

        while (list.empty() == false && index >= 0)
        {
            TreeNode *node = new TreeNode(list[index]);
            node->right = new TreeNode(--index);
            list.pop_back();
            index--;
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
}