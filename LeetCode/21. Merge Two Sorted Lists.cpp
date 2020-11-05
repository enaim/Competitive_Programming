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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL && l2==NULL)
            return l1;
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        ListNode* root = new ListNode();
        ListNode* cur = new ListNode();
        root = cur = NULL;
        int flag = 1;
        while(l1 != NULL && l2 != NULL)
        {
            if(flag)
            {
                flag = 0;
                if(l1->val < l2->val)
                    cur = l1, l1 = l1->next;
                else
                    cur = l2, l2 = l2->next;
                root = cur;
            }
            else
            {
                if(l1->val < l2->val)
                    cur->next = l1, l1 = l1->next;
                else
                    cur->next = l2, l2 = l2->next;
                cur = cur->next;
            }
        }
        if(l1 != NULL)
        {
            cur->next = l1;
            cur = cur->next;
        }
        if(l2 != NULL)
        {
            cur->next = l2;
            cur = cur->next;
        }
        return root;
    }
};
