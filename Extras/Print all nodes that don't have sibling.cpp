void FindNoSiblings(Node* root ,vector<int>&ans )
{
    if(root==NULL) return;
    if(root->left==NULL && root->right == NULL) return;
    if(root->left!=NULL && root->right != NULL) // if both nodes exist
    {
        FindNoSiblings(root->left,ans);
        FindNoSiblings(root->right,ans);
    }
    else if(root->left!=NULL) // if only left child exists 
    {
        ans.push_back(root->left->data);
         FindNoSiblings(root->left,ans);
    }
     else if(root->right!=NULL)  // if only right child exists 
    {
        ans.push_back(root->right->data);
         FindNoSiblings(root->right,ans);
    }
    return;
}
vector<int> noSibling(Node* node)
{
    // code here
    
    vector<int>ans;
    FindNoSiblings(node,ans);
    if(ans.size()== 0)
    {
        ans.push_back(-1);
    }
    sort(ans.begin(),ans.end());
    return ans;
}