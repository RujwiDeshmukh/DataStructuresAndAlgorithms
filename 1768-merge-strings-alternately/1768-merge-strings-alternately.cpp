class Solution {
public:
    string mergeAlternately(string word1, string word2) {
       
        int n = word1.size();
        int m = word2.size();
        
        int i=0, j=0;
        string word3="";
        
        while(i<n && j<m)
        { 
           word3 += word1[i];
           word3 += word2[j];
            i++;
            j++;
        }
        
         if(i<n)
        {
            word3 += word1.substr(i,n-i);
        }
        
         if(j<m)
        {
            word3 += word2.substr(j,m-j);
        }
        
        return word3;
    }
};