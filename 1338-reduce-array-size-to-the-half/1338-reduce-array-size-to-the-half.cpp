class Solution {
public:
    int minSetSize(vector<int>& arr) {
        
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