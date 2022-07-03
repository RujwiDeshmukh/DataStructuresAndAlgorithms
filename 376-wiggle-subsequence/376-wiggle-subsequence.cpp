class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        
        //greedy approach
        //https://leetcode.com/problems/wiggle-subsequence/discuss/1115385/Short-and-Easy-w-Explanation-or-O(N)-time-O(1)-Space
        
        //https://leetcode.com/problems/wiggle-subsequence/discuss/1115385/Short-and-Easy-w-Explanation-or-O(N)-time-O(1)-Space
        
          int n = nums.size();
          int len=1;
          int up=1;
          int down=1;
        
        for(int i=1;i<n;i++)
        {
            //valley
            if(nums[i] < nums[i-1])
            {
                down = 1 + up;
            }
            //peak
            else if(nums[i-1] < nums[i])
            {
                up = 1 + down;
            }
        }
        
        return max(up,down);
    }
};