class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        unordered_map<int,int>mp;
        int prefixSum = 0;
        mp[prefixSum] = 1;
        int ans=0;
        
        for(int i=0;i<nums.size();i++)
        {
            prefixSum += nums[i];
            if(mp.find(prefixSum-goal) != mp.end())
            {
                ans += mp[prefixSum-goal];
                mp[prefixSum]++;
            }
            else
            {
                mp[prefixSum]++;
            }
        }
        
        return ans;
    }
};