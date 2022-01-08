class Solution {
public:
    void solve(vector<int>& nums,int curr, int target,vector<int>&vec,set<vector<int>>&ans)
    {
         if(target==0)
        { 
            ans.insert(vec);
            return;
        }
        if(curr>=nums.size())
            return;
        int currval = nums[curr];
        
         if(target-currval>=0)
         {
            vec.push_back(currval);
            solve(nums,curr+1,target-currval,vec,ans);
            vec.pop_back();
         }
        while(curr+1<nums.size() && nums[curr]==nums[curr+1]){
            curr++;}
        solve(nums,curr+1,target,vec,ans);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set<vector<int>>ans;
         sort(candidates.begin(),candidates.end());
           vector<int>subset;
        
        solve(candidates,0,target,subset,ans);
      //  return dp;
        vector<vector<int>> numbers{ans.begin(), ans.end()};
         return numbers;
    }
};
