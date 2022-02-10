class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        
        unordered_map<int,int>mp;
        int count=0;
        
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        
        for(auto m : mp)
        {
            if(k==0)
            {
                if(m.second > 1)
                {
                    count++;
                }
            }
            else
            {
                if(mp.find(m.first+k) != mp.end())
                {
                    count++;
                }
            }
        }
        
        return count;
    }
};