/*  link of ques: https://leetcode.com/discuss/interview-question/1271034/count-no-of-subsets-with-given-difference-dp */
class Solution {
public:
    bool isPossible(vector<int>&nums,int curr,int targetsum,unordered_map<string,bool>&mp)
    {
        if(targetsum==0) return true;
        if(curr>=nums.size()) return false;
        string key = to_string(curr) + "_" + to_string(targetsum);
        if(mp.find(key)!=mp.end()) return mp[key];
        bool consider=false;
        if(nums[curr]<=targetsum){
         consider = isPossible(nums,curr+1,targetsum-nums[curr],mp);
        }
        if(consider){
             mp[key] = consider;
            return true;
        }
        bool notConsider = isPossible(nums,curr+1,targetsum,mp);
        mp[key] = consider||notConsider;
        return consider||notConsider;
    }
    bool canPartition(vector<int>& nums,int diff) {
        unordered_map<string,bool>mp;
        int totalsum = accumulate(nums.begin(),nums.end(),0);
        if((totalsum-diff)%2!=0) return false;
        return isPossible(nums,0,(totalsum-diff)/2,mp);
        
    }
};
