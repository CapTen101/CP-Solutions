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

//Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator
{
public:
    TreeNode *current;
    stack<TreeNode *> s;
    queue<TreeNode *> q;

    BSTIterator(TreeNode *root)
    {
        // In-Order traversal
        current = root;

        while (s.empty() == false || current != NULL)
        {
            while (current != NULL)
            {
                s.push(current);
                current = current->left;
            }

            current = s.top();
            q.push(current);
            s.pop();
            current = current->right;
        }
    }

    int next()
    {
        TreeNode *var = q.front();
        int value = var->val;
        q.pop();
        return value;
    }

    bool hasNext()
    {
        return !q.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

int main()
{
    ios_base::sync_with_stdio(false);
}