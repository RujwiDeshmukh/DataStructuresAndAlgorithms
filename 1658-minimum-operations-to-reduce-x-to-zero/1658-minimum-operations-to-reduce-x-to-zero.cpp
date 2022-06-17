class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
     
        int totalSum = accumulate(nums.begin(),nums.end(),0);
        cout<<totalSum<<endl;
        int targetSum = totalSum - x;
        int start=0;
        int end=0;
        int sum=0;
        int n = nums.size();
        int len=0;
        int max_len=-1;
        
        if(x > totalSum)
        {
            return -1;
        }
        
        while(end < n)
        {
            sum += nums[end];
            
            if(sum < targetSum)
            {
                end++;
                continue;
            }
            
            while(sum > targetSum)
            {
                sum -= nums[start];
                start++;
            }
            
            if(sum == targetSum)
            {
                len = end-start+1;
                max_len = max(max_len,len);
            }
            
            end++;
        }
        
        if(max_len == -1)
        {
            return max_len;
        }
        
        return n-max_len;
    }
};