class Solution {
public:
    
    int findWays(int ind,vector<int> & nums,int tar,vector<vector<int>>& dp)
    {
        
        if(ind==0)
        {
            if(tar==0 && nums[0]==0)
            {
                return 2;
            }
            
            if(tar==0 || nums[0]==tar)
            {
                return 1;
            }
            
            return 0;
        }
        
        if(dp[ind][tar] != -1)
        {
            return dp[ind][tar];
        }
        
        int notTake = findWays(ind-1,nums,tar,dp);
        int take=0;
        if(nums[ind] <= tar)
        {
            take = findWays(ind-1,nums,tar-nums[ind],dp);
        }
        
        return dp[ind][tar] = take+notTake;
    }
     
    int findTargetSumWays(vector<int>& arr, int tar) {
        
        int totSum = 0;
        
        int n = arr.size();
        
        for(int i=0;i<n;i++)
        {
            totSum += arr[i];
        }
        
        if(totSum-tar<0 || (totSum-tar)%2==1)
        {
            return 0;
        }
        
        int target = (totSum-tar)/2;
        
        cout<<target<<endl;
        
        vector<vector<int>>dp(n+1,vector<int>(target+1,0));
        
        if(arr[0]==0)
        {
           dp[0][0] = 2;    
        }
        else
        {
            dp[0][0] = 1;
            //target 0 at index 0 means only not pick will be true
            //as nums[0] is not equal to 0
        }
        
        if(arr[0] != 0 && arr[0] <= target)
        {
            dp[0][arr[0]] = 1;
        }
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=target;j++)
            {
                int notTake = dp[i-1][j];
                int take = 0;
                if(arr[i] <= j)
                {
                    take =  dp[i-1][j-arr[i]];
                }
                
                dp[i][j] = take+notTake;
            }
        }
        
        return dp[n-1][target];
    }
};