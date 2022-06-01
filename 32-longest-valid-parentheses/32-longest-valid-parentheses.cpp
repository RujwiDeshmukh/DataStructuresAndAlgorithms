class Solution {
public:
    int longestValidParentheses(string s) {
        
        stack<int>st;
        st.push(-1);
        int MAX=0;
        
        //https://leetcode.com/problems/longest-valid-parentheses/discuss/1139990/Longest-Valid-Parentheses-or-Short-and-Easy-w-Explanation-using-stack
        
        //https://leetcode.com/problems/longest-valid-parentheses/discuss/864061/C%2B%2B-O(n)-time-and-O(1)-space-(0ms-runtime-beats-100)-explained
        
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