class Solution {
public:
    int minSetSize(vector<int>& arr) {
        
        //https://leetcode.com/problems/reduce-array-size-to-the-half/discuss/1319437/Simple-Solution-w-Explanation-or-Delete-Elements-by-Max-Frequency-or-O(N)-Beats-100
        
        unordered_map<int,int>mp;
        multiset<int, greater<int>> mt;
        
        for(auto num : arr)
        {
            mp[num]++;
        }
        
        for(auto m : mp)
        {
            int freq = m.second;
            mt.insert(freq);
        }
        
        int deleted=0 , ans=0;
        
        for(auto freq : mt)
        {
            deleted += freq;
            ans++;
            
            if(deleted >= (arr.size())/2)
            {
                return ans;
            }
        }
        
        return -1;
    }
};