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
    int sumOfLeftLeaves(TreeNode* root) {
        return SumOfLeftLeaf(root,false);
    }
    int SumOfLeftLeaf(TreeNode* root, bool isLeft)
    {
        if(root == NULL) return 0;
        
        if(root->left == NULL && root->right==NULL and isLeft == true)   // check for left leaf node
            return root->val;
            
      int leftans = SumOfLeftLeaf(root->left,true);
      int rightans = SumOfLeftLeaf(root->right,false);
        return leftans+rightans;
    }
};
