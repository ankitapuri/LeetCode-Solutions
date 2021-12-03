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
    bool check(TreeNode* root1,TreeNode* root2)
    {
        if(root1==NULL && root2== NULL) return true;
        else if(root1==NULL ||root2== NULL) return false;
        else
            return ((root1->val == root2->val)&&check(root1->left,root2->right)
                   &&check(root1->right,root2->left));
        
    }
    bool isSymmetric(TreeNode* root) {
        return check(root->left,root->right);   
     }
};