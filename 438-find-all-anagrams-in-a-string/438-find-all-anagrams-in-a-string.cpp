class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        unordered_map<char,int>m1;
        unordered_map<char,int>m2;
        vector<int>res;
        
        if(p.size() > s.size())
        {
            return res;
        }
        
        for(int i=0;i<p.size();i++)
        {
            m1[p[i]]++;
        }
        
        int start=0,end=0;
        
        while(end < s.size())
        {
            m2[s[end]]++;
            
            if(end-start+1 < p.size())
            {
                end++;
                continue;
            }
            
            if(end-start+1 == p.size())
            {
               if(m1==m2)
               {
                  res.push_back(start);
               }
                
                m2[s[start]]--;
                if(m2[s[start]]==0)
                 {
                    m2.erase(s[start]);
                  }
                
                end++;
                start++;
            }
        }
        
        return res;
    }
};