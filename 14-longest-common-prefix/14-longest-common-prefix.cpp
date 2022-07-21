class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        int n = strs.size();
        string prefix = "";
        
        if(n==0)
        {
            return prefix;
        }
        
        prefix=strs[0];
        
        for(int i=1;i<n;i++)
        {
            if(strs[i].length() == 0)    
            {
               prefix=""; 
            }
            
            int j;
            for(j=0;j<prefix.length() && j<strs[i].length();j++)
            {
                if(prefix[j] != strs[i][j])
                {
                    break;
                }
            }
            
            prefix = prefix.substr(0,j);
        }
        
        return prefix;
    }
};