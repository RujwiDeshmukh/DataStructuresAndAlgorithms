class Solution {
public:
    
    int totalWays(int currentStair,int targetStair,unordered_map<int,int> &mp)
    {
        if(currentStair == targetStair)
        {
            return 1;
        }
        
        if(currentStair > targetStair)
        {
            return 0;
        }
        
        int currentKey = currentStair;
        
        if(mp.find(currentKey) != mp.end())
        {
            return mp[currentKey];
        }
        
        int oneStep = totalWays(currentStair+1,targetStair,mp);
        int twoSteps = totalWays(currentStair+2,targetStair,mp);
        
        return mp[currentKey] = oneStep+twoSteps;
    }
    
    int climbStairs(int n) {
         unordered_map<int,int>mp;
        return totalWays(0,n,mp);
    }
};