class Solution {
public:
    string longestPalindrome(string s) {
        
        int n = s.length();
        int max_length = 1;
        int low,high;
        int start=0;
        string ans;
        
        for(int i=1;i<n;i++)
        {
            low=i-1;
            high=i;
            
            //even palindrome
            while(low>=0 && high<n && (s[low]==s[high]))
            {
                int len = high-low+1;
                
                if(len>max_length)
                {
                    max_length=len;
                    start=low;
                }
                
                low--;
                high++;
            }
            
            //odd plaindrome
            low=i-1;
            high=i+1;
            while(low>=0 && high<n && (s[low]==s[high]))
            {
                int len=high-low+1;
                
                if(len>max_length)
                {
                    start=low;
                    max_length=len;
                }
                
                low--;
                high++;
            }
            
        }
        
        int end = start+max_length;
        
        for(int i=start;i<end;i++)
        {
            ans += s[i];
        }
        
        return ans;
    }
};