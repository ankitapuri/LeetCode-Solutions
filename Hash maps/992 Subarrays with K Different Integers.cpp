class Solution {
public:
 int solve(vector<int>&s, int k)
{
    int ans=0;
    int distinctcnt=0;
    int release=0;
    unordered_map<int,int>mp;
    for(int i=0;i<s.size();i++)
    {
       int currchar = s[i];
     if(mp.find(currchar)!=mp.end())
       mp[currchar]+=1;
       else
       {   distinctcnt+=1;
           mp[currchar]=1;
       }
       while(release<=i and distinctcnt>k)
       {
           int dischar = s[release];
           mp[dischar]-=1;
           release+=1;
        if(mp[dischar]==0)
        {
            mp.erase(dischar);
            distinctcnt-=1;
        }
          
       }
       ans+=(i-release+1); 
    }
    return ans;
}
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums,k)-solve(nums,k-1);
    }
};