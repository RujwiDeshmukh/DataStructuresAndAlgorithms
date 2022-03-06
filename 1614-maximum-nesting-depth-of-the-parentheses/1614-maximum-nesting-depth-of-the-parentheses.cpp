class Solution {
public:
    int maxDepth(string s) {
        
         /*
        if we read the que correctly, all vps are valid parenthesis that is equal closing and opening bracket
        que is input is a valid parwnthesis, we just need to count depth
        so depth of any char is no of open paranthesis till we reach that char
        
        so we could use stack for this count or to prevent space directly count the open paranthesis
        
        so max no of open parenthesis is ans.
        */
        
        int open=0;
        int res=0;
        
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
            {
                open++;
                res = max(res,open);
            }
            else if(s[i]==')')
            {
                open--;
            }
        }
        
        return res;
    }
};