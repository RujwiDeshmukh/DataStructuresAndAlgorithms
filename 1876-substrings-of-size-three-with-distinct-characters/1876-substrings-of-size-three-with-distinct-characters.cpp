class Solution {
public:
    int countGoodSubstrings(string s) {
        int count=0;
        int start=0 ,end=0;
        unordered_map<char,int>mp;
        
        while(end<s.length())
        {
            mp[s[end]]++;
            
            if(end-start+1<3)
            {
                end++;
            }
            else if(end-start+1==3)
            {
                if(mp.size()==3)
                {
                    count++;
                }
                
              mp[s[start]]--;
              
              if(mp[s[start]]==0)
              {
                  mp.erase(s[start]);
              }
                
            start++;
                end++;
            }
        }
        
        return count;
    }
};