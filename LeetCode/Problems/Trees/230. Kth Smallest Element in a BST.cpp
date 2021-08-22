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

void preOrder(TreeNode *root, int &k, priority_queue<int> &maxHeap)
{
    if (root == NULL)
        return;

    maxHeap.push(root->val);
    if (maxHeap.size() > k)
        maxHeap.pop();

    preOrder(root->left, k, maxHeap);
    preOrder(root->right, k, maxHeap);
}

int kthSmallest(TreeNode *root, int k)
{
    priority_queue<int> maxHeap;
    preOrder(root, k, maxHeap);
    return maxHeap.top();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}