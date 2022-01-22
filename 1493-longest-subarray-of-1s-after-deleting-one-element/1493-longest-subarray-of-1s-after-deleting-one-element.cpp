class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int countZero=0;
        int start=0, end=0;
        int ans=0;
        int res=0;
        
        while(end < nums.size())
        {
            if(nums[end]==0)
            {
                countZero++;
            }
            
            if(countZero <= 1)
            {
                ans = end-start+1;
                res = max(res,ans);
            }
            
            while(countZero > 1)
            {
                if(nums[start]==0)
                {
                    countZero--;
                }
                start++;
            }
            
            end++;
        }
        
        return res-1;
    }
};