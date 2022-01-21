class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int start=0;
        int end=0;
        int ans=0;
        int sum=0;
        int res=INT_MAX;
        
        while(end < nums.size())
        {
            sum += nums[end];
            if(target > sum)
            {
                end++;
                continue;
            }
            //it is example of variable size sliding window
            
            while(target <= sum)
            {
                ans = end-start+1;
              //  cout<<ans<<endl;
                res = min(ans,res);
                sum -= nums[start];
                start++;
            }
            end++;
        }
        
        if(res==INT_MAX)
        {
            return 0;
        }
        
        return res;
    }
};