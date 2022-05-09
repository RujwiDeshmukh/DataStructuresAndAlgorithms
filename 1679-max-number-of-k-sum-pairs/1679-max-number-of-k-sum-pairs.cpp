class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        
        //efficient appraoch that works in O(n) --->TC
        
        unordered_map<int,int>mp;
        int count=0;
        
        for(int i=0;i<nums.size();i++)
        {
            int res = k- nums[i];
            
            if(mp.find(res) != mp.end())
            {
                count++;
                mp[res]--;
                
                if(mp[res]==0)
                {
                    mp.erase(res);
                }
            }
            else
            {
                //insert the values into map i.e. are present in arrays
                mp[nums[i]] += 1;
            }
        }
        
        return count;
    }
    
};