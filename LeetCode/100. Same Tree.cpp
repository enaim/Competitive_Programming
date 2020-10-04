/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int flag;

void check(TreeNode* p, TreeNode* q)
{
    if(flag==0)
        return;
    if(p==NULL && q==NULL)
        return;
    if(p==NULL || q==NULL)
    {
        flag = 0;
        return;
    }
    if(p->val!=q->val)
    {
        flag = 0;
        return;
    }
    check(p->left,q->left);
    check(p->right,q->right);
}

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        flag = 1;
        check(p,q);
        if(flag)
            return true;
        return false;
    }
};
