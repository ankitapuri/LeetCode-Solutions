class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int>res;
    void Top(Node*root,int dis , int level , auto &mp)
    {
        if(root==NULL) return;
        if(mp.find(dis)==mp.end() || level<mp[dis].second)
        {
            mp[dis]={root->data,level};
            }
        Top(root->left,dis-1,level+1,mp);
        Top(root->right,dis+1,level+1,mp);
    }
    vector<int> topView(Node *root)
    {
        //Your code here
        map<int,pair<int,int>>mp;
        Top(root,0,0,mp);
        for (auto it: mp) {
        res.push_back(it.second.first);
    }

    return res;
    }

};

// method 2

class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
         vector<int> ans;
        if(root==NULL)
        return ans;
        
        map<int,int> mpp;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            Node* node=it.first;
            int line=it.second;
            if(mpp.find(line)==mpp.end())
            mpp[line]=node->data;
            
            if(node->left!=NULL)
            q.push({node->left,line-1});
            
            if(node->right!=NULL)
            q.push({node->right,line+1});
    
        }
        
        for(auto it : mpp){
            ans.push_back(it.second);
            }
            
            return ans;
    
    }

};