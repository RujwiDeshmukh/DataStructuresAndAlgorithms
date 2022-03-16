class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int n = nums.size();
        int ans=0;
        
        for(int i=0;i<n;i++)
        {
            int val = abs(nums[i]);
            
            if(nums[val] > 0)
            {
                nums[val] = -nums[val];
            }
            else
            {
                ans = abs(nums[i]);
                break;
            }
        }
        
        return ans;
    }
};