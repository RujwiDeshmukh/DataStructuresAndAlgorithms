class Solution {
public:
    
    int maxMoney(vector<int>& nums,int currentIndex,unordered_map<int,int>& mp)
    {
        if(currentIndex < 0)
        {
            return 0;
        }
        
        int currentKey = currentIndex;
        
        if(mp.find(currentKey) != mp.end())
        {
            return mp[currentKey];
        }
        
       //rob the house 
        int rob = nums[currentIndex] + maxMoney(nums,currentIndex-2,mp);
        //not to rob the house
        int noRob = maxMoney(nums,currentIndex-1,mp);
        
        return mp[currentKey] = max(rob,noRob);
    }
    
    int rob(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n= nums.size()-1;
        return maxMoney(nums,n,mp);
    }
};