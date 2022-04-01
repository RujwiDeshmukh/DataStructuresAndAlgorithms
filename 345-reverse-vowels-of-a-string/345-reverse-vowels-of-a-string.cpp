class Solution {
public:
    
    bool isVowel(char ch)
    {
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'
          || ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U')
        {
            return true;
        }
        
        return false;
    }
    
    
    string reverseVowels(string s) {
        
        int n = s.length()-1;
        
        int l=0;
        int r=n;
        
        while(l<r)
        {
            if(isVowel(s[l]) && isVowel(s[r]))
            {
                swap(s[l],s[r]);
                l++;
                r--;
            }
            else if(isVowel(s[l]))
            {
                r--;
            }
            else if(isVowel(s[r]))
            {
                l++;
            }
            else
            {
                l++;
                r--;
            }
        }
        
        return s;
    }
};