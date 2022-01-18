class Solution {
public:
    int countGoodSubstrings(string s) {
        int start=0 ,end=0, count=0;
        int k=3;
        unordered_map<char,int>mp;
        for(end=0;end<k;end++)
        {
            mp[s[end]]++;
        }
        
        if(mp.size()==k)
        {
            count++;
        }
        
        for(end=k;end<s.length();end++)
        {
            mp[s[end]]++;
            
            mp[s[end-k]]--;
            
            if(mp[s[end-k]]==0)
            {
                mp.erase(s[end-k]);
            }
            
            if(mp.size()==k)
            {
                count++;
            }
        }
        return count;
    }
};