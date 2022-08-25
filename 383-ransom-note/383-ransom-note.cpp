class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        unordered_map<char,int>mp;
        
        for(auto st : magazine)
        {
            mp[st]++;
        }
        
        for(auto note : ransomNote)
        {
            if(mp.find(note) == mp.end())
            {
                return false;
            }
            
            mp[note]--;
            
            if(mp[note]==0)
            {
                mp.erase(note);
            }
        }
        
        return true;
        
    }
};