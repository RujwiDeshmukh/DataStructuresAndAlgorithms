class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        unordered_map<int,int>mp;
        int answer=0;
        int prefixSum=0;
        
        //we are inserting prefixSum zero at -1 index
        mp.insert({0,-1});
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                prefixSum += -1;
            }
            else
            {
                prefixSum += 1;
            }
            
            
            if(mp.find(prefixSum) != mp.end())
            {
                int len = i-mp[prefixSum];
                answer = max(len,answer);
            }
            else
            {
                mp[prefixSum]=i;
            }
        }
        return answer;
    }
};