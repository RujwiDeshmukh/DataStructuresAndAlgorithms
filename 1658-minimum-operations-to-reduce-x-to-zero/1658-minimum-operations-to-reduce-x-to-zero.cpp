class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        int totalSum = accumulate(nums.begin(),nums.end(),0);
        int target = totalSum - x;
        int ans = -1;
        int sum=0;
        int res=0;
        
        if(x > totalSum)
        {
            return -1;
        }
        
        int end=0, start=0;
        
        while(end < nums.size())
        {
            sum += nums[end];
            
            if(sum < target)
            {
                end++;
                continue;
            }
        
            while(sum > target)
            {
                sum -= nums[start];
                start++;
            }
            
            
              if(sum == target)
            {
                res = end-start+1;
                ans = max(ans,res);
                cout<<ans;
            }
            
            end++;
        }
        
        if(ans==-1)
        {
            return ans;
        }
        
        return nums.size()-ans;
    }
};