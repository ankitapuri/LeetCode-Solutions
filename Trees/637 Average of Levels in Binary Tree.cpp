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
    vector<double>res;
    map<int, vector<int>>mp;
    void avglevel(TreeNode* root, int level)
    {
        if(root==NULL) return;
        if(mp.find(level)!=mp.end())
        {
            mp[level].push_back(root->val);
        }
        else{
            mp[level]=vector<int>{root->val};
        }
        avglevel(root->left,level+1);
        avglevel(root->right,level+1);
        return;
    }
    vector<double> averageOfLevels(TreeNode* root) {
       avglevel(root,0);  
        for (auto itr = mp.begin(); itr != mp.end(); ++itr) {
            double sum = 0;
            for(auto i: itr->second){
                sum += double(i);
            }
            res.push_back(sum/itr->second.size());
        }
         return res;
    }
        
    };