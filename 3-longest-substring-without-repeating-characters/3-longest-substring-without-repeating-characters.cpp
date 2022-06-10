class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_map<char,int>mp;
        int start=0;
        int res=0;
        int ans=0;
        
        for(int end=0;end<s.size();end++)
        {
            if(mp.find(s[end]) != mp.end() &&  mp[s[end]] >= start )
            {
                start = mp[s[end]]+1;
            }
            
            res = end-start+1;
            mp[s[end]] = end;
            ans = max(ans,res);
        }
        
        return ans;
    }
};