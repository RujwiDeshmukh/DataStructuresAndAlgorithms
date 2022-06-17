class Solution {
public:
    string longestPalindrome(string s) {

        int n = s.length();
        int low,high;
        string ans="";
        int start=0;
        int max_length=1;
        int len=0;
        
        for(int i=1;i<n;i++)
        {
            //check for even palindrome
            low = i-1;
            high = i;
        while(low >= 0 && high<n && s[low]==s[high])
          {
                len = high-low+1;
                
            if(len >  max_length)
            {
                max_length = len;
                start=low;
            }
            
            low--;
            high++;
          }
            
            //check for odd palindrome
            
            low = i-1;
            high = i+1;
            
         while(low >= 0 && high<n && s[low]==s[high])
            {
                len = high-low+1;
               
                if(len > max_length)
                {
                    max_length = len;
                    start=low;
                }
                low--;
                high++;
            }
        }
        
        int end = max_length+start;
        for(int i=start;i<end;i++)
        {
            ans += s[i];
        }
        
        
        return ans;
    }
};