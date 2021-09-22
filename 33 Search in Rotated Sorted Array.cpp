class Solution {
public:
    int binary_search(vector<int>arr,int l , int h , int k)
    {
        if (h < l)
        return -1;
           int mid=(l+h)/2;
           if (k == arr[mid])
             return mid;
           else if (k > arr[mid])
            return binary_search(arr, (mid + 1), h, k);
           else
            return binary_search(arr, l, (mid - 1), k);
        
    }
    int findpivot(vector<int>arr, int low, int high)
{
    
    if (high < low)
        return -1;
    if (high == low)
        return low;
 
    int mid = (low + high) / 2; 
    if (mid < high && arr[mid] > arr[mid + 1])
        return mid;
 
    else if (mid > low && arr[mid] < arr[mid - 1])
        return (mid - 1);
 
    else if (arr[low] >= arr[mid])
        return findpivot(arr, low, mid - 1);
 
   else return findpivot(arr, mid + 1, high);
}
    int search(vector<int>A, int target) {
        int n = A.size();
        int pivot=findpivot(A,0,n-1);
        if(pivot==-1)
        {
            return binary_search(A,0,n-1,target);
        }
        if(A[pivot]==target)
        return pivot;
        else if(A[0]<=target)
        return binary_search(A,0,pivot-1,target);
        else
        return binary_search(A,pivot+1,n-1,target);
    }
};