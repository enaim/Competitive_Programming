/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* go(ListNode* head)
{
    if(head==NULL || head->next==NULL)
        return head;
    ListNode* rest = go(head->next);

    head->next->next = head;
    head->next = NULL;
    return rest;
}

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        return go(head);
    }
};
