class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int ans = 0;
        unordered_map<int,int>mp;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            int currval = nums[i];
            if(mp.find(currval)!=mp.end())
                mp[currval]+=1;
            else
                mp[currval]=1;
        }
        for(auto it=mp.begin();it!=mp.end();it++)
        {
          ans+=(it->second*(it->second-1))/2;   
        }
        return ans;
    }
};

// ref for formula --  https://donic0211.medium.com/leetcode-1512-number-of-good-pairs-a285a07a68e1