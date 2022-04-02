class Solution {
public:
    int rob(vector<int>& nums) {
     
        int n = nums.size();
        
        int dp[n+1];
        
        //we got to know that from recursive tree
        dp[0] = nums[0];
        int pick=0;
        
        for(int i=1;i<n;i++)
        {
         i > 1 ? pick = nums[i] + dp[i-2] : pick = nums[i]; //+ dp[i-2] ll be 0 as i ind is -ve;
        
          int notPick = dp[i-1];
            
         dp[i] = max(pick,notPick);
        }
        
        return dp[n-1];
        
    }
};