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
    void reorderList(ListNode* head) {
        ListNode* root = head;
        int cnt = 0;
        while(head!=NULL)
        {
            cnt++;
            head = head->next;
        }

        int ar[cnt+5];
        cnt = 0;
        head = root;
        while(head!=NULL)
        {
            ar[cnt++]=head->val;
            head = head->next;
        }

        int i = 0, j=cnt-1;
        head = root;
        int n = cnt;
        cnt = 0;
        while(cnt<n)
        {
            if(cnt%2==0)
            {
                root->val = ar[i];
                root = root->next;
                i++;
            }
            else
            {
                root->val = ar[j];
                root = root->next;
                j--;
            }
            cnt++;
        }
    }
};
