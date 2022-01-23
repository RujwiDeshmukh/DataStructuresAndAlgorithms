class Solution {
public:
    int minSwaps(vector<int>& nums) {
        
        int n = nums.size();
        int ones=0;
        int start=0 , end=0;
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]==1)
            {
                ones++;
            }
        }
        
        if(ones <= 1)
        {
            return 0;
        }
        

        int k = ones;
        int maxOnes=0;
        int count=0;
        
        while(end < n+k)
        {
            if(nums[end%n]==1)
            {
                count++;
            }
            
            if(end-start+1 < k)
            {
                end++;
                continue;
            }
            
            if(end-start+1 == k)
            {
                
               // cout<<"Count : "<<count<<endl;
                maxOnes = max(maxOnes,count);
                if(nums[start%n]==1)
                {
                    count--;
                }
                start++;

            }
            end++;
        }
        
        
        return (k-maxOnes);
    }
    
    //https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/discuss/1680055/Easy-understanding-C%2B%2B-code-with-approach
};