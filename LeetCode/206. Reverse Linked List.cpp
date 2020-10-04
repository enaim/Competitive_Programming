/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* current = head;
        ListNode *prev=NULL,*next=NULL;
        while(current!=NULL)
        {
            next = current->next;
            current->next = prev;

            prev = current;
            current = next;
        }
        head = prev;
        return head;
    }
};
