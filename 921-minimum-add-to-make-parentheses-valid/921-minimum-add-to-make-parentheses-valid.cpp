class Solution {
public:
    int minAddToMakeValid(string s) {
        
        //as we have to find the minimum so here greedy technique is used
        
        stack<char>st;
    
        int n = s.length();
        
        for(int i=0;i<n;i++)
        {
            //here we are only checking if the pair exists 
            if(!st.empty() && s[i]==')' && st.top()=='(')
            {
              st.pop();   
            }
            //"(()))()(("  --> test case explains everything
            //pushing the parenthesis whether it is opening or closing
            else
            {
                st.push(s[i]);
            }
        }
        
        int count=0;
        
        while(!st.empty())
        {
            count++;
            st.pop();
        }
        
        return count;
    }
};