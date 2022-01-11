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
    int ans=0;  // we need to initialize it globally else it will become zero in every condition.
    int rangeSumBST(TreeNode* root, int low, int high) {
        
        if(root==NULL) return 0;
        if(root->val>=low && root->val<=high)
        {
              ans+=root->val;
             rangeSumBST(root->left,low,high);
             rangeSumBST(root->right,low,high);
                     
        }
       
         else if(root->val<low)  rangeSumBST(root->right,low,high);
         else if(root->val>high) rangeSumBST(root->left,low,high);
        return ans;
    }
};
