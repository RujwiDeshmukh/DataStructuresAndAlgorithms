class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        if(nums.size() <= 0)
        {
            return 0;
        }
        
        sort(nums.begin(),nums.end());
        int curr_longest=1;
        int ans=0;
        
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==nums[i-1])
            {
                continue;
            }
            else if(nums[i]==nums[i-1]+1)
            {
                curr_longest++;
            }
            else
            {
                ans = max(curr_longest,ans);
                curr_longest=1;
            }
        }
        //we are not directly returning ans from here 
        //as there is possibility that array is continuously increasing array
        //so it wont fall into the last else condition so we are using here maximum
        return max(curr_longest,ans);
    }
};