class Solution {
public:
    bool isValid(string s) {
        
        stack<int>st;
        for(int i=0;i<s.length();i++)
        {
            char currChar = s[i];
            
            if(currChar=='(' || currChar=='{' || currChar=='[')
            {
                st.push(currChar);
            }
            else
            {
                if(st.empty())
                {
                    return false;
                }
                else if(st.top()=='(' && currChar==')')
                {
                    st.pop();
                }
                else if(st.top()=='[' && currChar==']')
                {
                    st.pop();
                }
                else if(st.top()=='{' && currChar=='}')
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        if(st.empty())
        {
            return true;
        }
        
        return false;
    }
};