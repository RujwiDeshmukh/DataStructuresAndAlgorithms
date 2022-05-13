class Solution {
public:
    bool backspaceCompare(string s, string t) {
         
         stack<char>s1,s2;
        
       // https://leetcode.com/problems/backspace-string-compare/discuss/2034032/Easiest-C%2B%2B-explanation-everoror-explained-with-comments
        
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!='#')
            {
                s1.push(s[i]);
            }
            else if(s[i]=='#' && s1.size()>=1)
            {
              s1.pop();
            }
        }
        
        for(int j=0;j<t.size();j++)
        {
            if(t[j]!='#')
            {
                s2.push(t[j]);
            }
            else if( t[j]=='#' && s2.size()>=1)
            {
                s2.pop();
            }
        }
        
        if(s1.size() != s2.size())
        {
            return false;
        }
        
        while(!s1.empty())
        {
            
            char a = s1.top();
            s1.pop();
            char b = s2.top();
            s2.pop();
            
            
            if(a != b)
            {
                return false;
            }
        }
        
        return true;
    }
};