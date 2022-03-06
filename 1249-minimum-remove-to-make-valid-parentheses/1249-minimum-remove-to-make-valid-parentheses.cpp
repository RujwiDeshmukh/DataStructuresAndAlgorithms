class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        //first my approach was to create stack of pair storing 
        //opening braces and index as we want to remove that brace from string
        
        //as we know that we are only pushing braces to stack
        
        int n = s.length();
        stack<int>st;
        
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                st.push(i);
            }
            else
            {
                if(s[i]==')')
                {
                    if(st.empty())
                    {
                        s[i]='#';
                    }
                 else
                   {
                    st.pop();
                   }
                    
                }
            }
        }
        
        while(!st.empty())
        {
            s[st.top()]='#';
            st.pop();
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
    }
};