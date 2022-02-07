class Solution {
public:
    char findTheDifference(string s, string t) {
        
        char ans;
        
       /* if(s.size() >= t.size())
        { 
            return ans;
        }*/
        
        unordered_map<char,int>mp;
        
        for(int i=0;i<t.size();i++)
        {
            mp[t[i]]++;
        }
        
        for(int i=0;i<s.size();i++)
        {
            if(mp.find(s[i]) != mp.end())
            {
                mp[s[i]]--;
            }
            
            if(mp[s[i]]==0)
            {
                mp.erase(s[i]);
            }
        }
        
        for(auto m : mp)
        {
            ans = m.first;
        }
        
        return ans;
    }
};