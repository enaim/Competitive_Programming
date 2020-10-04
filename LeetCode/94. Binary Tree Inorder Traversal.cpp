/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

vector<int>vec;

void inorder(TreeNode* root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    vec.push_back(root->val);
    inorder(root->right);
}

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vec.clear();
        inorder(root);
        return vec;
    }
};
