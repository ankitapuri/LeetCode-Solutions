/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* curr = root;
        while(curr!=NULL)
        {
            if(curr->val>p->val && curr->val>q->val)
                curr = curr->left;
            else if(curr->val<p->val && curr->val<q->val)
                curr = curr->right;
            else  //if one is in leftsubtree and other in right subtree
                return curr;
        }
        return NULL;
    }
};