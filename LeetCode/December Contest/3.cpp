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

    void inorder(TreeNode *root)
    {
        if (root == NULL)
            return;

        inorder(root->left);
        list.push_back(root->val);
        inorder(root->right);
    }

    TreeNode *increasingBST(TreeNode *root)
    {
        inorder(root);
        int index = 0;
        TreeNode *newRoot = new TreeNode(list[index]);
        TreeNode *current = newRoot;

        while (index < list.size())
        {
            index++;
            if (index >= list.size())
                break;

            current->right = new TreeNode(list[index]);
            current = current->right;
        }

        return newRoot;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
}