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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int>inordermap = populateMap(inorder);
        int postIndex =postorder.size()-1;
        return constructTree(postorder,inordermap,0,inorder.size()-1,postIndex);
    }
    unordered_map<int,int> populateMap(vector<int>& inorder)
    {
        unordered_map<int,int>mp;
        for(int i=0;i<inorder.size();i++)
        {
            mp[inorder[i]]=i;
        }
        return mp;
    }
    TreeNode* constructTree(vector<int>& postorder,unordered_map<int,int>&inordermap,int start,int end ,int &postIndex)
    {
        if(start>end) return NULL;
        TreeNode* root = new TreeNode(postorder[postIndex]);
        int currIndex = inordermap[postorder[postIndex]];
        postIndex-=1;
        root->right =constructTree(postorder,inordermap,currIndex+1,end,postIndex); 
        root->left = constructTree(postorder,inordermap,start,currIndex-1,postIndex);
        return root;
    }
};