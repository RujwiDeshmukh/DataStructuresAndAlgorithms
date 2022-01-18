class Solution {
public:
    int countGoodSubstrings(string s) {
        
        int count=0;
        int start=0, end=0;
        
        while(end<s.length())
        {
            if(end-start+1<3)
            {
                end++;
            }
            
            else if(end-start+1==3)
            {
if((s[start]!=s[start+1] && s[start]!=s[start+2]) && (s[start+1]!=s[start] && s[start+1]!=s[start+2]) && (s[start+2]!=s[start+1] && s[start+2]!=s[start]))
    {
        count++;
    }
                start++;
                end++;
            }
        }
        
        return count;
    }
};