class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        
       //https://leetcode.com/problems/shortest-unsorted-continuous-subarray/discuss/2003057/TWO-POINTERS-APPROACH-%2B-MEME
        
        int prev = nums[0];
        //as array should be in ascending order then
        //previous can never be greater than current element
        
        int n = nums.size();
        int end=-1;
        int start=0;
        
        for(int i=1;i<n;i++)
        {
            if(prev > nums[i])
            {
                //order not matched ,here is loop hole 
                end=i;
            }
            else
            {
                prev = nums[i];
            }
        }
        
        int last = nums[n-1];
        
        for(int i=n-2;i>=0;i--)
        {
            if(last < nums[i])
            {
                start=i;
            }
            else
            {
                last = nums[i];
            }
        }
        
        return end-start+1;
    }
};