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

// Definition for a Node.
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
public:
    Node *connect(Node *root)
    {
        if (root == NULL)
            return NULL;

        int level = 0;
        vector<pair<int, Node *>> list;
        queue<Node *> q;
        q.push(root);

        while (q.empty() == false)
        {
            Node *temp = q.front();
            list.push_back({level, temp});
            q.pop();

            if (temp->left != NULL)
                q.push(temp->left);

            if (temp->right != NULL)
                q.push(temp->right);

            level++;
        }

        level = 0;

        for (int i = 1; i < list.size(); i++)
        {
            if (i == list.size() - 1)
                break;

            if (i == 0)
                continue;

            if (list[i].first == level && list[i + 1].first == level)
            {
                list[i].second->next = list[i + 1].second;
                continue;
            }
        }

        return root;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
}