class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        
        //greedy approach
        
        int prevDiff=0;
        int n = nums.size();
        int currDiff;
        int len=1;
        
        for(int i=1;i<n;i++)
        {
            currDiff = nums[i] - nums[i-1];
            
            if((prevDiff <= 0 && currDiff > 0)  ||  (prevDiff >= 0 && currDiff < 0))
            {
                len++;
                prevDiff=currDiff;
            }
        }
        
        return len;
    }
};