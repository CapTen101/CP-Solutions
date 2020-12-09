#include <bits/stdc++.h>
using namespace std;

#define start \
    int t;    \
    cin >> t; \
    while (t--)

struct Node
{
    int data;
    Node *right;
    Node *left;
};

void inorder(Node *root)
{
    Node *current = root;
    stack<Node *> s;

    while (current != NULL || s.empty() == false)
    {
        while (current != NULL)
        {
            s.push(current);
            current = current->left; // go all the way to left bottom.
        }
        current = s.top();     // take the top most element of stack (bottom most element of the tree)
        cout << current->data; // print it

        s.pop(); // remove it

        current = current->right; // shift current to right and repeat the same process
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
}