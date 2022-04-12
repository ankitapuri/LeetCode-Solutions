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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
        if(root->val>key) 
            root->left = deleteNode(root->left,key);
        else if(root->val<key)
            root->right = deleteNode(root->right,key);
        else  // root->val == key condition 
        {
            if(root->left==NULL && root->right==NULL)  // if it is a leaf node then just make it NULL
            {
                root = NULL;
                return root;
            }
            if(root->left!=NULL && root->right==NULL)  // if single child on left side
            {
                root = root->left;
                return root;
            }
            if(root->right!=NULL && root->left==NULL)  // if single child on right side
            {
                root = root->right;
                return root;
            }
           // TreeNode *rightsubtree = root->right;
            TreeNode* tempnode = findleftmostNode(root->right);
            int temp = root->val;
            root->val = tempnode->val;
            tempnode->val = temp;
            
            root->right = deleteNode(root->right,tempnode->val);
            return root;
        }
        return root;
    }
    TreeNode* findleftmostNode(TreeNode* currnode)
    {
        while(currnode->left!=NULL)
            currnode = currnode->left;
        return currnode;
    }
};