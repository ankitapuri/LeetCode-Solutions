class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans=0 , prefixsum=0;
        unordered_map<int,int>mp;
        mp[prefixsum]=1;
        for(int i=0;i<nums.size();i++)
        {
            prefixsum+=nums[i]; 
            int rem = ((prefixsum%k)+k)%k;   // for handling negative cases as well
            if(mp.find(rem)!=mp.end())
            {
                ans+=mp[rem];
                mp[rem]+=1;
            }
            else
                mp[rem]=1;
        }
        return ans;
    }
};