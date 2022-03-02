class Solution {
public:
    bool isSubsequence(string s, string t) {
     
         int m = s.length();
         int n = t.length();
        
        int j=0;
        
        for(int i=0; j<m && i<n;i++)
        {
            //increment only if the matching character is found
            if(s[j]==t[i])
            {
                j++;
            }
        }
        
        //check the pointer is equal to j
        return (j==m);
    }
};