class Solution {
public:
    int NoOfWays(vector<int>& nums, int target,int curr,unordered_map<string,int>&mp)
    {
        if(curr>=nums.size() && target!=0) return 0;
        if(curr>=nums.size() && target==0) return 1;
        string currkey = to_string(curr)+"_"+to_string(target);
        if(mp.find(currkey)!=mp.end()) return mp[currkey];
        int plus = NoOfWays(nums,target-nums[curr],curr+1,mp);
        int minus = NoOfWays(nums,target+nums[curr],curr+1,mp);
        mp[currkey] = plus+minus;
        return plus+minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
    unordered_map<string,int>mp;
     return NoOfWays(nums,target,0,mp);   
    }
};