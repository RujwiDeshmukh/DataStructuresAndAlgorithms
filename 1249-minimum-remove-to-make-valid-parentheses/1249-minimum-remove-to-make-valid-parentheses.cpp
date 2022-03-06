class Solution {
public:
    string minRemoveToMakeValid(string s) {
     
        int n = s.length();
        int count=0;
        
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                count++;
            }
            else if(s[i]==')')
            {
                if(count==0)
                {
                    s[i]='#';
                }
                else
                {
                    count--;
                }
            }
        }
        
        count=0;
        
        
         for(int i=n-1;i>=0;i--)
        {
            if(s[i]==')')
            {
                count++;
            }
            else if(s[i]=='(')
            {
                if(count==0)
                {
                    s[i]='#';
                }
                else
                {
                    count--;
                }
            }
        }
        
        string ans="";
        
        for(int i=0;i<n;i++)
        {
            if(s[i]!='#')
            {
                ans.push_back(s[i]);
            }
        }
        
        return ans;
        
//https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/discuss/1073189/C%2B%2B-or-2-Approaches-or-O(n)-Beats-100-or-No-Extra-Space-(Best)-or-Explanation
    }
};