class Solution {
public:
    string convert(string s, int numRows) {
             
       // https://leetcode.com/problems/zigzag-conversion/discuss/920510/c%2B%2B(8ms-90)-very-easy-for-understand-(with-commentaries)
             
        vector<string> tmp(numRows);
        int n = s.size();
        string ans; 
        int i=0;
        
        while(i<n)
        {
           for(int j=0;j<numRows && i<n;j++,i++)
           {
               tmp[j] += s[i];
               //cannot push_back here as we have already initialized the array
           }
            
           for(int j=numRows-2;j>0 && i<n;j--,i++)
           {
               tmp[j] += s[i];
           }
        }
        
        for(int i=0;i<numRows;i++)
        {
            ans += tmp[i];
        }
        
        return ans;
    }
};