/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        long prev_val[1] = {-99999999999};
        return isBST(root,prev_val);
    }
    
    bool isBST(TreeNode* root,long prev_val[1])
    {
        if(root==NULL) return true;
        bool leftans = isBST(root->left,prev_val);
        if(root->val<=prev_val[0]) return false;
        prev_val[0] = root->val;
        bool rightans = isBST(root->right,prev_val);
        return leftans && rightans;
    }
};