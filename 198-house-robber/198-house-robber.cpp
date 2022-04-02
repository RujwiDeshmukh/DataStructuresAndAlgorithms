class Solution {
public:
    int rob(vector<int>& nums) {
     
        int n = nums.size();
        
        //int dp[n+1];
        
        //we got to know that from recursive tree
        //rather than using dp array use variables to reduce the space complexity
        //dp[0] = nums[0];
        int pick=0;
        
        int prev = nums[0];
        int prev2 = 0;
        
        for(int i=1;i<n;i++)
        {
         i > 1 ? pick = nums[i] + prev2 : pick = nums[i]; //+ dp[i-2] ll be 0 as i ind is -ve;
        
          int notPick = prev;
            
         int curr = max(pick,notPick);
            
         prev2 = prev;
            
         prev = curr;
            
        }
        
        return prev;
        
    }
};