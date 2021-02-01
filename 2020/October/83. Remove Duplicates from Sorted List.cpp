/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL)
            return head;
        ListNode* root = new ListNode();
        ListNode* cur = new ListNode();
        root = head;
        cur = head;
        head = head->next;
        while(head != NULL)
        {
            if(cur->val!=head->val)
            {
                cur->next =  head;
                cur = cur->next;
            }
            head = head->next;
        }
        cur -> next = NULL;
        return root;
    }
};
