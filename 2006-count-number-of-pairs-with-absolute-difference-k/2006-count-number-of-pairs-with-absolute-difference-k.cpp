class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
     
        unordered_map<int,int>mp;
        int ans=0;
        
        for(int i=0;i<nums.size();i++)
        {
             mp[nums[i]]++;
        }
        
        
        for(auto m : mp)
        {
            if(mp.find(m.first+k) != mp.end())
            {
                auto it = mp.find(m.first+k);
                ans += m.second*it->second;
            }
        }
        
        return ans;
    }
};