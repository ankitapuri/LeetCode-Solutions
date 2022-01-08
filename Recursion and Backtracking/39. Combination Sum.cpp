class Solution {
public:
    void totalways(vector<int>&nums,int curr,int target,vector<int>&vec,vector<vector<int>>&all)
    {
        if(target==0)
        {  all.push_back(vec);
           return;}
        if(curr>=nums.size())
            return;
        int currval = nums[curr];
        
        if(target>=currval)
        {
            vec.push_back(currval);
            totalways(nums,curr,target-currval,vec,all);
            vec.pop_back();
        }
        totalways(nums,curr+1,target,vec,all);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>all;
        vector<int>vec;
        totalways(candidates,0,target,vec,all);
        return all;
    }
};