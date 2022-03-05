class Solution {
public:
    
    bool op(string ch)
    {
        if(ch=="+" || ch=="-" || ch=="*" || ch=="/")
        {
            return true;
        }
        
        return false;
    }
    
    int evalRPN(vector<string>& tokens) {
     
          stack<int>st;
          int n = tokens.size();
          int ans=0;
        
        for(int i=0;i<n;i++)
        {
            
            if(op(tokens[i]))
            {
                int op2 = st.top();
                st.pop();
                int op1 = st.top();
                st.pop();
                
                if(tokens[i]=="+") 
                { ans = op1+op2;
                st.push(ans); }
                
                  if(tokens[i]=="-") 
                { ans = op1-op2;
                st.push(ans); }
                
                  if(tokens[i]=="*") 
                { ans = op1*op2;
                st.push(ans); }
                
                  if(tokens[i]=="/") 
                { ans = op1/op2;
                st.push(ans); }
            }
            else
            {
                st.push(stoi(tokens[i]));
            }
        }
        
        return st.top();
    }
};