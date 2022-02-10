class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int answer=0;
        unordered_map<int,int>mp;
        //saving prefix sum and freq in hash map
        int prefixSum=0;
        mp[prefixSum] = 1;
        
        int n = nums.size();
        
        for(int i=0;i<n;i++)
        {
            prefixSum += nums[i];
            
            if(mp.find(prefixSum-k) != mp.end())
            {
                answer += mp[prefixSum-k];
            }
            
            mp[prefixSum]++;
        }
        
        return answer;
    }
};