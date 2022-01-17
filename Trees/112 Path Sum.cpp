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
    bool hasPathSum(TreeNode* root, int targetSum) {
        return isPossible(root,targetSum,0);
    }
    bool isPossible(TreeNode* root,int target , int sum)
    {
        if(root == NULL) return false;
        if(root->left == NULL && root->right==NULL)
            return sum+root->val == target;
     return isPossible(root->left,target,sum+root->val) || isPossible(root->right,target,sum+root->val) ;
        
    }
};