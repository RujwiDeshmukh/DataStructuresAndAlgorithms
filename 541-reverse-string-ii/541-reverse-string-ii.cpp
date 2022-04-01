class Solution {
public:
    string reverseStr(string s, int k) {
        
        int n = s.length()-1;
        
        for(int i=0;i<=n;i=i+2*k)
        {
            if(n-i<2*k && n-i>=k)
            {
                reverse(s.begin()+i,s.begin()+i+k);
                break;
            }
            else if(n-i<k)
            {
                reverse(s.begin()+i,s.end());
            }
            else
            {
                reverse(s.begin()+i,s.begin()+i+k);
            }
        }
        
        return s;
    }
};