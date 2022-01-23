class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        unordered_map<char,int>mp1;
        unordered_map<char,int>mp2;
        vector<int>res;
        
        if(p.size() > s.size())
        {
            return res;
        }
        
        for(int i=0;i<p.size();i++)
        {
         mp1[p[i]]++;
        }
        
        int start=0 ,end =0;
        
        while(end < s.size())
        {
            mp2[s[end]]++;
            if(end-start+1 < p.size())
            {
                end++;
                continue;
            }
            
            if(end-start+1 == p.size())
            {
                if(mp1 == mp2)
                {
                    res.push_back(start);
                }
                
                mp2[s[start]]--;
                if(mp2[s[start]]==0)
                {
                    mp2.erase(s[start]);
                }
                start++;
                end++;
            }
        }
        
        return res;
        
    }
};