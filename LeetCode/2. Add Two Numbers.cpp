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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        string a,b;
        while(l1 != NULL)
        {
            char ch = (l1->val+48);
            l1 = l1->next;
            a+=ch;
        }
        while(l2!= NULL)
        {
            char ch = (l2->val+48);
            l2 = l2->next;
            b+=ch;
        }
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        string sum;
        int n = a.size();
        int m = b.size();
        int rem = 0;
        while(n && m)
        {
            n--;
            m--;
            int temp = (a[n]+b[m])-('0'+'0') + rem;
            rem = temp/10;
            temp%=10;
            char ch = (temp+'0');
            sum+=ch;

        }
        while(n)
        {
            n--;
            int temp = a[n] - '0' + rem;
            rem = temp/10;
            temp%=10;
            char ch = (temp+'0');
            sum+=ch;
        }
        while(m)
        {
            m--;
            int temp = b[m] - '0' + rem;
            rem = temp/10;
            temp%=10;
            char ch = (temp+'0');
            sum+=ch;
        }
        if(rem)
        {
            char ch = (rem+'0');
            sum+=ch;
        }

        ListNode* T = NULL;
        ListNode *current_node;

        for(int i=0;i<sum.size();i++)
        {
            if(i==0)
            {
                T = new ListNode(sum[i]-'0');
                T->next = NULL;
                current_node = T;
                continue;
            }
            current_node->next = new ListNode(sum[i]-'0');
            current_node = current_node->next;
        }
        return T;

    }
};
