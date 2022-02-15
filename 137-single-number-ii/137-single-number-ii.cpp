class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        unordered_map<int,int>mp;
        int ans=0;
        
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        
        for(auto m : mp)
        {
            if(m.second == 1)
            {
                ans = m.first;
            }
        }
        
        return ans;
    }
};