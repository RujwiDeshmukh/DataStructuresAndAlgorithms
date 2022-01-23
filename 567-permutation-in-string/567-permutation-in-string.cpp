class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        unordered_map<char,int>mp1, mp2;
        
        for(int i=0;i<s1.size();i++)
        {
            mp1[s1[i]]++;
        }
        
        int start=0;
        int end=0;
        
        while(end < s2.size())
        {
            mp2[s2[end]]++;
            
            if(end-start+1 < s1.size())
            {
                end++;
                continue;
            }
            
            if(end-start+1 == s1.size())
            {
                if(mp1==mp2)
                {
                    return true;
                }
                
                mp2[s2[start]]--;
                if(mp2[s2[start]]==0)
                {
                    mp2.erase(s2[start]);
                }
                start++;
                end++;
            }
        }
        return false;
    }
};