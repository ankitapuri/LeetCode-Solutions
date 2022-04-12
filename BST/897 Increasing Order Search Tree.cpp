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
    TreeNode* increasingBST(TreeNode* root) {
        vector<int>traversal;
        InorderTraversal(root,traversal);
        
        TreeNode* dummy =  new TreeNode(-1);  // we used it so that we don't need to set the initial root to NULL
        TreeNode* newroot = dummy;
        for(auto i : traversal)
        {
            dummy->right = new TreeNode(i);  // create a new node
            dummy = dummy->right;   // setting the new node to the right
        }
        return newroot->right;
    }
    void InorderTraversal(TreeNode*root, vector<int>&ans)
    {
        if(root==NULL) return;
        InorderTraversal(root->left,ans);
        ans.push_back(root->val);
        InorderTraversal(root->right,ans);
    }
};