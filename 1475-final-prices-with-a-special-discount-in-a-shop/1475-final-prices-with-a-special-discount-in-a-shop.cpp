class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        
        int n = prices.size();
        stack<int>st;
        
        for(int i=0;i<n;i++)
        {
            //here we are maintaining the stack such that until first smaller element
            //encounters,once the element is encountered then we will pop the larger 
            //elements than the current elements so while loop is used
            //we are putting index in stack as we want to reduce the array value
            //so that we can access the array element using index
            while(!st.empty() && prices[st.top()] >= prices[i])
            {
                prices[st.top()] -= prices[i];
                st.pop();
            }
            
            st.push(i);
        }
        
        return prices;
    }
};