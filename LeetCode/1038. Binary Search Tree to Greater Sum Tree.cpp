/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int sum[110];
int ar[110];
int cnt;

void BST1(TreeNode *root)
{
    if(root==NULL)
        return;
    sum[cnt++]=root->val;
    BST1(root->left);
    BST1(root->right);
    return;
}

void BST2(TreeNode *root)
{
    if(root==NULL)
        return;
    int temp = root->val;
    int left,right,mid;
    left = 0;
    right = cnt;
    while(left<=right)
    {
        mid = (left+right)/2;
        if(sum[mid]<temp)
            left = mid+1;
        else
            right = mid-1;
    }
    if(right==-1)
        root->val = ar[cnt-1];
    else
        root->val = ar[cnt-1]-ar[right];

    BST2(root->left);
    BST2(root->right);
    return;
}

class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        cnt = 0;
        BST1(root);
        sort(&sum[0],&sum[cnt]);
        ar[0]=sum[0];
        for(int i=1;i<cnt;i++)
            ar[i]=sum[i]+ar[i-1];

        BST2(root);

        return root;
    }
};
