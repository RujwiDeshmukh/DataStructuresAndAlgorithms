class Solution {
public:
    int longestValidParentheses(string s) {
        
        stack<int>st;
        st.push(-1);
        int MAX=0;
        
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                st.push(i);
            }
            else
            {
                if(!st.empty())
                {
                    st.pop();
                }
                if(st.empty())
                {
                    st.push(i);
                }
                else
                {
                   MAX = max(MAX, i-st.top()); 
                }
            }
        }
        return MAX;
    }
};