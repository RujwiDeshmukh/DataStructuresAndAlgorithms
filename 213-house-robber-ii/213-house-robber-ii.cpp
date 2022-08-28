class Solution {
public:
    
    int maxMoney(int ind,vector<int>& nums,vector<int>& dp)
    {
        if(ind==0)
        {
            return nums[0];
        }
        
        if(ind<0)
        {
            return 0;
        }
        
        if(dp[ind] != -1)
        {
            return dp[ind];
        }
        
        int pick = nums[ind]+maxMoney(ind-2,nums,dp);
        int notPick = maxMoney(ind-1,nums,dp);
        
        return dp[ind] = max(pick,notPick);
    }
    
    int rob(vector<int>& nums) { 
        
        if(nums.size()==1)
        {
            return nums[0];
        }
        
        vector<int>dp(nums.size(),-1);
        
        //here we are not taking into consideration last element
        //i.e. not including the last element of the array into operation
        int LastInd = maxMoney(nums.size()-2,nums,dp);
        //reversing the existing array now tha last element will be the first element
        //so we are not including the last element of array into operation
        reverse(nums.begin(),nums.end());
        
        fill(dp.begin(),dp.end(),-1);
        
        int ZeroInd = maxMoney(nums.size()-2,nums,dp);
        
        return max(LastInd,ZeroInd);
    }
};