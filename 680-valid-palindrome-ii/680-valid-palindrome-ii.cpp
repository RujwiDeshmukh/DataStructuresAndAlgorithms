class Solution {
public:
    //https://leetcode.com/kritika_12/
    bool isPalindrome(string s,int l ,int r)
    {
        while(l<r)
        {
            if(s[l] != s[r])
            {
                return false;
            }
            
            l++;
            r--;
        }
        
        return true;
    }
    
    
    bool validPalindrome(string s) {
        
        int l = 0;
        int r = s.length()-1;
        
        while(l<r)
        {
            if(s[l] != s[r])
            {
                if(isPalindrome(s,l+1,r) || isPalindrome(s,l,r-1))
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            
            l++;
            r--;
        }
        
        return true;
    }
};