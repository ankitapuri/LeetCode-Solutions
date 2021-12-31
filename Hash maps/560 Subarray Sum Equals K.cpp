class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        int prefixsum=0;
        unordered_map<int,int>mp;
        mp[prefixsum]=1;
        for(int i=0;i<nums.size();i++)
        {
           prefixsum+=nums[i];
            if(mp.find(prefixsum-k)!=mp.end())
                ans+=mp[prefixsum-k];
            if(mp.find(prefixsum)!=mp.end())
                mp[prefixsum]=mp[prefixsum]+1; 
            else
                mp[prefixsum]=1;
        }
        return ans;
    }
};