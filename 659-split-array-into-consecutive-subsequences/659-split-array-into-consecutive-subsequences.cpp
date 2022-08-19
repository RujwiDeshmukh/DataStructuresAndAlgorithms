class Solution {
public:
    bool isPossible(vector<int>& nums) {
        
        unordered_map<int,int>freq;
        
        for(auto num : nums)
        {
            freq[num]++;
        }
       // https://leetcode.com/problems/split-array-into-consecutive-subsequences/discuss/2446913/C%2B%2B-oror-Greedy-oror-Fully-Commented-oror-Simplest-Solution-Of-All
        
        unordered_map<int,int>need;
        
        for(auto num : nums)
        {
            if(freq[num]==0) continue;
            
            if(need[num] > 0)
            {
                freq[num]--;
                need[num]--;
                need[num+1]++;
            }
            else if(freq[num]>0 && freq[num+1]>0 && freq[num+2]>0)
            {
                freq[num]--;
                freq[num+1]--;
                freq[num+2]--;
                
                need[num+3]++;
            }
            else 
            {
                return false;
            }
        }
        
        return true;
    }
};