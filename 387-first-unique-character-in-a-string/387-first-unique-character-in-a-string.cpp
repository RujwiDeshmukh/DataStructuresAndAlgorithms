class Solution {
public:
    int firstUniqChar(string s) {
        
        unordered_map<char,pair<int,int>>mp;
        
        int n = s.size();
        int idx = s.size();
        
        for(int i=0;i<n;i++)
        {
            mp[s[i]].first++;
            mp[s[i]].second=i;
        }
        
        for(auto m : mp)
        {
            auto p = m.second;
            if(p.first==1)
            {
                idx = min(idx,p.second);
            }
        }
        
        return idx == s.size() ? -1 : idx;
    }
};