class Solution {
public:
    
    int findFirstPos(vector<int>& nums,int target)
    {
        
        int n = nums.size();
        int start=0;
        int end=n-1;
        int ans=-1;
        
         while(start<=end)
        {
            int mid = start + (end-start)/2;
            cout<<mid<<endl;
            
            if(nums[mid]==target)
            {
                ans=mid;
                end=mid-1;
            }
            else if(nums[mid] < target)
            {
                start = mid+1;
            }
            else
            {
                end = mid-1;
            }
        }
        
        return ans;
    }
    
    int findLastPos(vector<int>& nums,int target)
    {
         int n = nums.size();
        int start=0;
        int end=n-1;
        int ans=-1;
        
         while(start<=end)
        {
            int mid = start + (end-start)/2;
            cout<<mid<<endl;
            
            if(nums[mid]==target)
            {
                ans=mid;
                start=mid+1;
            }
            else if(nums[mid] < target)
            {
                start = mid+1;
            }
            else
            {
                end = mid-1;
            }
        }
        
        return ans;
    }
    
    
    vector<int> searchRange(vector<int>& nums, int target) {
        
        vector<int>res(2,-1);
        
        res[0] = findFirstPos(nums,target);
        
        if(res[0]==-1)
        {
            return res;
        }
        
        res[1] = findLastPos(nums,target);
        
        return res;
    }
};