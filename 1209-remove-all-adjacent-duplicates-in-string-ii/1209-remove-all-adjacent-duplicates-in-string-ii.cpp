class Solution {
public:
    
    //https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/discuss/1296662/Easy-C%2B%2B-solution-using-stacks-with-comments
    
    //https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/discuss/1995282/c%2B%2B-oror-stack-based-solution
    
    string removeDuplicates(string s, int k) {
        
        
        stack<pair<char,int>>st;
        
        for(int i=0;i<s.size();i++)
        {
            if(st.empty())
            {
               st.push({s[i],1});
            }
            else
            {
                if(st.top().first == s[i])
                {
                    st.top().second++;
                }
                else
                {
                    st.push({s[i],1});
                }
            }
            
            if(!st.empty() && st.top().second==k)
            {
                st.pop();
            }
        }
        
        
        string ans="";
        while(!st.empty())
        {
            auto curr = st.top();
            st.pop();
            
            ans = string(curr.second, curr.first) + ans;
        
        }
        
        return ans;
    }
};