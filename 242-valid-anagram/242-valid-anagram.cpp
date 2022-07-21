class Solution {
public:
    bool isAnagram(string s, string t) {
        
        unordered_map<char,int>mp;
        
        if(s.size() != t.size())
        {
            return false;
        }
        
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]++;
        }
        
        for(int i=0;i<t.size();i++)
        {
            char ch = t[i];
            
            if(mp.find(ch) != mp.end())
            {
                mp[ch]--;
                if(mp[ch]==0)
                {
                    mp.erase(ch);
                }
            }
            else
            {
                return false;
            }
        }
        if(mp.size()==0)
        {
            return true;
        }
        return false;
    }
};