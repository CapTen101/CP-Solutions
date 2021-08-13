#include <bits/stdc++.h>
using namespace std;

// Definition for a n-ary tree node.
class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

void helper(Node *node, vector<int> &nodes)
{
    if (!node)
        return;

    nodes.push_back(node->val);
    vector<Node *> v = node->children;
    for (auto child : v)
    {
        helper(child, nodes);
    }
}

vector<int> preorder(Node *root)
{
    vector<int> v;
    helper(root, v);
    return v;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}