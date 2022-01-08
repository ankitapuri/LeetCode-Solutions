class Solution {
public:
     void generateSubsets(vector<int>& nums,int curr,vector<int>&currSubset,set<vector<int>>&power_set)
    {
        if(curr>=nums.size()){
            power_set.insert(currSubset); // its passed by value in cpp so we don't need to make a copy
           return;
        }
        int currval = nums[curr]; 
        currSubset.push_back(currval);
        generateSubsets(nums,curr+1,currSubset,power_set); // remove the current val to make the fxn for not        //consideration
        currSubset.pop_back();
    generateSubsets(nums,curr+1,currSubset,power_set);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>>ans;
        vector<int>vec;
        sort(nums.begin(),nums.end());
         generateSubsets(nums,0,vec,ans);
        vector<vector<int>> numbers{ans.begin(), ans.end()};
         return numbers;
    }
};