class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int sum=0;
        int max_sum = INT_MIN;
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] < sum+nums[i])
            {
                sum = sum+nums[i];
            }
            else
            {
                sum = nums[i];
            }
            
            if(sum > max_sum)
            {
                max_sum = sum;
            }
        }
        
        return max_sum;
    }
};