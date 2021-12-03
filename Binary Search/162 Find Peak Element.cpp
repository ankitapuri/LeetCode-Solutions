class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = n-1;
        while(l<=r)
        {
            int mid = (l+r)/2;
            if((mid ==0 || nums[mid]>=nums[mid-1]) && (mid == n-1 || nums[mid]>= nums[mid+1]))
                 return mid;
            else if(mid >0 && nums[mid]<nums[mid-1]) r= mid-1;
            else l= mid+1;
        }
        return -1;
    }
};