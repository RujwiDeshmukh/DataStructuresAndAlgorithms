class Solution {
public:
    
    //Striver's Space Optimized Solution
    
    int maxMoney(vector<int>& nums)
    {   
        int prev = nums[0];
        int prev2=0;
        
        for(int i=1;i<nums.size();i++)
        {
            int take = nums[i];
            if(i>1)
            {
                take += prev2;
            }
            int notTake = prev;
            
            int curr = max(take,notTake);
            
            prev2 = prev;
            prev = curr;
        }
        
        return prev;
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        return maxMoney(nums);
    }
};