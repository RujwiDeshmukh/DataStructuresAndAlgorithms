class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        unordered_map<int,int>mp;
        vector<int>ans;
        
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        
        for(auto m : mp)
        {
            if(m.second == 1)
            {
                ans.push_back(m.first);
            }
        }
        
        return ans;
    }
};