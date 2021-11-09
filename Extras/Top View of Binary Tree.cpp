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