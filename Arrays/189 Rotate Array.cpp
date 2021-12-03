class Solution {
public:
    void reverse_arr(vector<int>&nums,int start,int end)
    {
        while(start<end)
        {
            swap(nums[start],nums[end]);
            start++;
            end--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k=k%n;
        if(k==0)return;
        // reverse the entire vector
        reverse_arr(nums,0,n-1);
        // reverse the first k elements
        reverse_arr(nums,0,k-1);
        // reverse the remaining elements
        reverse_arr(nums,k,n-1);
        
        
    }
};