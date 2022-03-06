class Solution {
public:
    int minSwaps(string s) {
        
        //as we need to find minimum number of swaps 
        //minimum means either greedy or dp so here we are using greedy approach
        
        //https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/discuss/1390595/C%2B%2B-(stack-always-comes-to-rescue-in-parentheses-qns)
        
//https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/discuss/1390319/How-to-reach-the-optimal-solution-or-Explained-with-Intuition-and-Diagram
        
//https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/discuss/1390811/Clear-Explanation-oror-C%2ACB%2B-oror-Greedy-oror-Detailed-Explanation
        
         stack<char>st;
        int n = s.length();
        
        for(int i=0;i<n;i++)
        {
            if(s[i]=='[')
            {
                st.push(s[i]);
            }
            else
            {
               if(!st.empty() && s[i]==']') 
               {
                   st.pop();
               }
            }
        }
        
        return (st.size()+1)/2;
        
    }
};