class Solution {
public:
    bool search(vector<int>& nums, int target) {
        
         //as array is sorted we can apply binary search
        
        int start=0;
        int end=nums.size()-1;
        
        //end and start can point to same element and that element can be target element
        //so equal to should be used
        while(start<=end)
        {
            //first calculate the middle element
            
            //to aviod duplicates
            
            while(start < end && nums[start] == nums[start+1])
            {
                start++;
            }
            
            while(start < end && nums[end] == nums[end-1])
            {
                end--;
            }
            
            int mid = (start+end)/2;
            
            if(nums[mid]==target)
            {
                return true;
            }
            
            
            //if 1st part is unsorted
            
            if(nums[start] > nums[mid])
            {
                if(nums[mid] < target && target <= nums[end])
                {
                    start = mid+1;
                }
                else
                {
                    end = mid-1;
                }
            }
            
            //2nd part is unsorted
            
            else if(nums[mid] > nums[end])
            {
                if(nums[mid] > target && nums[start] <= target)
                {
                    end = mid-1;
                }
                else
                {
                    start=mid+1;
                }
            }
            //condition when all the elements in array are same
            //at some place when can face the situation where both the parts are sorted
            //at some subproblem where 0 1 2 where 0 is start 1 is mid 2 is end
            //0 is target here
            else
            {
                if(nums[mid]<target)
                {
                      start = mid+1;
                }
                else
                {
                    end = mid-1;
                }
            }
        }
        return false;
    }
};