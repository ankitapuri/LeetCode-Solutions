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
//  T.C.---- 0(n) (No of nodes)
//  S.C.----0(h) (height of the tree)
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;
        int leftans= maxDepth(root->left);
        int rightans = maxDepth(root->right);
        int height = 1+max(leftans,rightans);
        return height;
       }
};