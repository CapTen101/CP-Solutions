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
    ListNode *deleteDuplicates(ListNode *head)
    {

        if (head == NULL || head->next == NULL)
            return head;

        ListNode *sentinel = new ListNode(0, head);
        ListNode *pred = sentinel;

        while (head != NULL)
        {
            if (head->next != NULL && head->val == head->next->val)
            {
                while (head->next != NULL && head->next->val == head->val)
                    head = head->next;

                pred->next = head->next;
            }
            else
            {
                pred = pred->next;
            }

            head = head->next;
        }

        return sentinel->next;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
}