class Solution {
public:
    string removeKdigits(string num, int k) {
        
        stack<char>st;
        string ans="";
        
        if(num.size()==k)
        {
            return "0";
        }
        
        int i=0;
        while(i< num.size())
        {
            while(!st.empty() && st.top() > num[i] && k)
            {
                st.pop();
                k--;
            }
            
            if(num[i] == '0' )
            { 
                if(!st.empty())
                {
                st.push(num[i]);
                }
            }
            else
            {
                st.push(num[i]);
            }
            
            i++;
        }
        
        //all elemnts in decreasing or equal order
        //or k elemnts are not removed as conditions are not valid
        while(k>0 && !st.empty())
        {
            k--;
            cout<<st.top()<<endl;
            st.pop();
            
        }
        
        while(!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans=="" ? "0" : ans;;
        
    }
};