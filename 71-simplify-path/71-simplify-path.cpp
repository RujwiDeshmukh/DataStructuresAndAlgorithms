class Solution {
public:
    string simplifyPath(string path) {
        
        stack<string>st;
        
        int n = path.length();
        
        for(int i=0;i<n;i++)
        {
            //now we are identifiying the word in between the slashes
            //and pushing to the stack
            
            string temp="";
            
            while(i<n && path[i]=='/')
            {
                i++;
            }
            
            while(i<n && path[i]!='/')
            {
                temp.push_back(path[i]);
                i++;
            }
            
            //as we want to move one directory back 
            //so popping the element from stack
            if(temp=="..")
            {
                if(!st.empty())
                {
                    st.pop();
                }
            }
            
            else if(temp==".")
            {
                continue;
            }
            
            else if(temp.length() != 0)
            {
                st.push(temp);
            }
        }
        
        
        string ans = "";
        ans += "/";
        
        cout<<ans<<endl;
        
        stack<string>st1;
        
        while(!st.empty())
        {
            st1.push(st.top());
            st.pop();
        }
        
        
        cout<<st1.size()<<endl;
        while(st1.size() > 1)
        {
            ans += st1.top();
            ans += "/";
            st1.pop();
        }
        
        if(!st1.empty())
        {
        ans += st1.top();
        }
        
        return ans;
    }
};