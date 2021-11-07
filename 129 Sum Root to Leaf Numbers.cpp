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
    int sum(TreeNode* root,string path)
    {
        if(root->left==NULL && root->right==NULL)
            return stoi(path);
        int leftans= 0;
        int rightans = 0;
        if(root->left)
        {
            leftans = sum(root->left,path+to_string(root->left->val));
        }
        if(root->right)
        {
            rightans = sum(root->right,path+to_string(root->right->val));
        }
        return leftans+rightans;
    }
    int sumNumbers(TreeNode* root) {
        return sum(root , ""+to_string(root->val));
        
    }
};