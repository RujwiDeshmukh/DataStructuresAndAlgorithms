class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        int n = asteroids.size();
        stack<int>st;
        vector<int>ans;
        
        for(int i=0;i<n;i++)
        {
            int currAster = asteroids[i];
            
            if(currAster > 0)
            {
                st.push(currAster);
            }
            
            else
            {
                while(!st.empty() && st.top() < abs(currAster) &&  st.top() > 0)
                {
                    st.pop();
                }
                
                if(!st.empty() && st.top() == abs(currAster))
                {
                    st.pop();
                }
                else if(!st.empty()  && st.top() < 0)
                {
                    st.push(currAster);
                }
                else if(st.empty())
                {
                    st.push(currAster);
                }
            }
        }
        
        while(!st.empty())
        {
            int ele = st.top();
            ans.push_back(ele);
            st.pop();
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};