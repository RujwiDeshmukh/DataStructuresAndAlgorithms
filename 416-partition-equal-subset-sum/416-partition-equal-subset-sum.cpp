class Solution {
public:
    bool canPartition(vector<int>& nums) {
        
        int n = nums.size();
        int totSum=0;
        
      /*  if(n==1)
        {
            return false;
        }
        */
        
        for(int i=0;i<n;i++)
        {
            totSum += nums[i];
        }
        
        if(totSum%2 == 1)
        {
            return false;
        }
        
        int target = totSum/2;
        
        //vector<vector<bool>>dp(n+5,vector<bool>(target+5,false));
        vector<bool>prev(target+1,false);
        
        //for target zero everytime it will be true
        
        prev[0] = true;
        
        //as target is 50 and our first element here is 99 so
        //it will give the error so every time target should be 
        //equal to nums[0] or always greatre than zero
        if(target >= nums[0])
        {
            prev[nums[0]]=true;
        }
        
        for(int i=1;i<n;i++)
        {
            //number of columns will be equal to target value
            //so the size of curr will be equal to target only
            vector<bool>curr(target+1,false);
               
            for(int j=1;j<=target;j++)
            {
                bool notTake = prev[j];
                bool take = false;
                
                if(nums[i] <= j)
                {
                    take = prev[j-nums[i]];
                }
                
                curr[j] = take | notTake;
            }
            
            prev = curr;
        }
        
        return prev[target];
        
    }
};