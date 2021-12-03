class Solution {
public:
    int totalComb(vector<int>& nums, int target,int curr,vector<vector<int>>&vec)
    {
        if(target==0) return 1;
        if(curr>=nums.size() || target<0) return 0;
        if(vec[curr][target]!=-1) return vec[curr][target];
        int consider = totalComb(nums,target-nums[curr],0,vec);
        int notconsider = totalComb(nums,target,curr+1,vec);
        return vec[curr][target]=consider+notconsider;
        
    }
    int combinationSum4(vector<int>& nums, int target) {
       vector<vector<int>>vec(nums.size()+1,vector<int>(1002,-1)); 
        return totalComb(nums,target,0,vec);
    }
};