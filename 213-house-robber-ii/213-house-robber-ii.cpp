class Solution {
public:
    
    int maxMoney(int currentIndex,int n,unordered_map<int,int>& mp,vector<int> & nums)
    {
        if(currentIndex >= n)
        {
            return 0;
        }
        
        if(mp.find(currentIndex) != mp.end())
        {
            return mp[currentIndex];
        }
        
        int rob = nums[currentIndex]+maxMoney(currentIndex+2,n,mp,nums);
        
        int notRob = maxMoney(currentIndex+1,n,mp,nums);
        
        return mp[currentIndex] = max(rob,notRob);
    }
    
    int rob(vector<int>& nums) {
        
        unordered_map<int,int>mp;
        
        if(nums.size()==1)
        {
            return nums[0];
        }
        
        int zeroIndex = maxMoney(0,nums.size()-1,mp,nums);
        mp.clear();
        int firstIndex = maxMoney(1,nums.size(),mp,nums);
        return max(zeroIndex,firstIndex);
    }
};