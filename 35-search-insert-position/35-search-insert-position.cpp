class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int n = nums.size();
        int start=0;
        int end=n-1;
        int ans=-1;
        
        while(start<=end)
        {
            int mid = start + (end-start)/2;
            
            if(nums[mid]==target)
            {
                return mid;
            }
            else if(nums[mid] < target)
            {
                start = mid+1;
            }
            else
            {
                ans=mid;
                end = mid-1;
            }
        }
        
      return ans == -1 ? n : ans;
        
    
    }
};