class Solution {
public:
    int maxMoney(vector<int>&nums,int curr,unordered_map<int,int>&mp)
    {
      if(curr>=nums.size()) return 0;
        int currkey = curr;
        if(mp.find(currkey)!=mp.end())
            return mp[curr];
        int yes_rob = nums[curr]+maxMoney(nums,curr+2,mp);
        int no_rob = maxMoney(nums,curr+1,mp);
        mp[curr] = max(yes_rob,no_rob);
        return mp[curr];  
    }
    
    int rob(vector<int>& nums) {
        unordered_map<int,int>mp;
        return maxMoney(nums,0,mp);
        
    }
};


