class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int>res;
        for(int i=0;i<nums.size();i++)
        {
            if(count(nums.begin(),nums.end(),nums[i])==1)
                res.push_back(nums[i]);
        }
        
        return res;
    }
};