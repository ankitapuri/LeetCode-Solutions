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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        RootToLeaf(root,"",ans);
        return ans;
    }
    void RootToLeaf(TreeNode* root, string currpath,vector<string>&ans)
    {
        if(root == NULL) return;
        if(root->left ==NULL && root->right ==NULL) // check for root node
        {
            currpath+= to_string(root->val);  
            ans.push_back(currpath);// add the value of root node in the end and then return
            return;
        }
        currpath+= to_string(root->val)+"->";
       RootToLeaf(root->left,currpath,ans); 
        // we don't need to pop back because the strings don't hold value in recursion
        RootToLeaf(root->right,currpath,ans);  
    }
};


