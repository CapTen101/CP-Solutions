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

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */

    vector<int> list;
    int length;

    Solution(ListNode *head)
    {
        ListNode *current = head;
        list.push_back(head->val);
        length = 1;

        while (current->next != NULL)
        {
            current = current->next;
            list.push_back(current->val);
            length++;
        }

        list.resize(length);
    }

    /** Returns a random node's value. */
    int getRandom()
    {
        int random_index = rand() % length;
        return list[random_index];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */

int main()
{
    ios_base::sync_with_stdio(false);
}