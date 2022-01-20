class Solution {
public:
    
    bool isNice(string &s,int start,int end)
    {
        unordered_map<int,bool>mp;
        
        for(int i=start;i<=end;i++)
        {
            mp[s[i]]=true;
        }
        
        while(start<=end)
        {
            if(s[start]<97)
            {
                if(mp[s[start]+32]==false)
                {
                    return false;
                }
            }
            else
            {
                if(mp[s[start]-32]==false)
                {
                    return false;
                }
            }
            
            start++;
        }
        return true;
    }
    
    string longestNiceSubstring(string s) {
        
        int maxLen=0;
        string result="";
        
        for(int i=0;i<s.size();i++)
        {
            for(int j=i;j<s.size();j++)
            {
                if(isNice(s,i,j))
                {
                    if(j-i+1 > maxLen)
                    {
                        maxLen = j-i+1;
                        //first index and length parameter
                        result = s.substr(i,j-i+1);
                    }
                }
            }
        }
        
        return result;
    }
};