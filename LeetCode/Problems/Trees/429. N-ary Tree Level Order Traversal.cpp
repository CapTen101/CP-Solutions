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

vector<vector<int>> levelOrder(Node *root)
{
    vector<vector<int>> v;
    if (root == NULL)
        return v;

    queue<Node *> q;
    q.push(root);

    while (q.size())
    {
        int size = q.size();
        vector<int> level;
        for (int i = 0; i < size; i++)
        {
            Node *current = q.front();
            q.pop();
            level.push_back(current->val);

            vector<Node *> child = current->children;
            for (Node *temp : child)
            {
                if (temp)
                    q.push(temp);
            }
        }
        v.push_back(level);
    }

    return v;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}