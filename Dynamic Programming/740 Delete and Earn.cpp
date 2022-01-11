class Solution {
public:
    
    int MaxPoints(vector<int>& nums,int curr,vector<int>&dp)
    {
        if(curr>=nums.size()) return 0;
        if(dp[curr]!=-1) return dp[curr];
         int consider = 0, notconsider=0;   
        consider = nums[curr]+MaxPoints(nums,curr+2,dp);
       notconsider = MaxPoints(nums,curr+1,dp);
        return dp[curr] = max(consider,notconsider);
        
    }
    int deleteAndEarn(vector<int>& nums) {
       vector<int>dp(20001,-1);
         vector<int>arr(20001,0);
        // for(auto num : nums) arr[num] += num;
        for(int i=0;i<nums.size();i++)
        {
            arr[nums[i]]+=nums[i];  
            // here we have taken the total sum of the elements of array at a particular index 
            // for eg - [3,4,2] the final arr=[3,7,9] 
            // by using this we can use the concept of House robber and find the ans. 
        }
        return MaxPoints(arr,0,dp);
    }
};