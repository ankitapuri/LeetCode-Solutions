class Solution {
public:
    void generateSubsets(vector<int>& nums,int curr,vector<int>&currSubset,vector<vector<int>>&power_set)
    {
        if(curr>=nums.size()){
            power_set.push_back(currSubset); // its passed by value in cpp so we don't need to make a copy
           return;}
        int currval = nums[curr]; 
        currSubset.push_back(currval);
        generateSubsets(nums,curr+1,currSubset,power_set);
    // remove the current val to make the fxn for not consideration
        currSubset.pop_back();
    generateSubsets(nums,curr+1,currSubset,power_set);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>power_set;
        vector<int>vec;
        generateSubsets(nums,0,vec,power_set);
        return power_set;
    }
};