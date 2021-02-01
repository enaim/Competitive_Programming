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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* cur = new ListNode();
        cur = head;
        head = NULL;
        int flag = 0;
        ListNode* root = new ListNode();
        root = NULL;
        while(cur!=NULL)
        {
            if(cur->val!=val)
            {
                if(flag==0)
                {
                    flag = 1;
                    root = cur;
                    head = cur;
                }
                else
                {
                    head->next = cur;
                    head = head->next;
                }
            }
            cur = cur->next;
        }
        if(flag==0)
            root = NULL;
        else
            head->next = NULL;
        return root;
    }
};
