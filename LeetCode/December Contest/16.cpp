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

// Use iterative In-Order DFS Traversal
class Solution
{
public:
    bool isValidBST(TreeNode *root)
    {
        if (root == NULL)
            return true;

        stack<TreeNode *> s;
        TreeNode *prev = NULL;

        while (s.empty() == false || root != NULL)
        {
            while (root != NULL)
            {
                s.push(root);
                root = root->left;
            }

            root = s.top();
            if (prev != NULL && prev->val >= root->val)
                return false;
            prev = root;
            root = root->right;
            s.pop();
        }

        return true;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
}