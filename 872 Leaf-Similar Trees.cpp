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
    void leafnodes(TreeNode* root,vector<int>&leaf)
    {
        if(root==NULL)return;
        if(root->left==NULL && root->right==NULL)
        {
            leaf.push_back(root->val);
            
        }
        leafnodes(root->left,leaf);
        leafnodes(root->right,leaf);
        
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>leaf1;
        leafnodes(root1,leaf1);
        vector<int>leaf2;
        leafnodes(root2,leaf2);
        return (leaf1 == leaf2);
        
    }
};