class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;
        int prefixsum=0;
        int ans = 0;
        mp[prefixsum]=-1;
       for(int i=0;i<n;i++)
       {
           int currval = nums[i];
           if(currval == 0)
           {
               prefixsum+=-1;
           }
           else 
             prefixsum+=1;
           if(mp.find(prefixsum)!=mp.end())
           {int temp = i-mp[prefixsum];
            ans = max(temp,ans);
           }
           else
           mp[prefixsum]= i;
       }
       return ans;
    }
};