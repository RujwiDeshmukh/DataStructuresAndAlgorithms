class Solution {
public:
    
    int convert(char ch)
    {
        if(ch=='I')
        {
            return 1;
        }
        else if(ch=='V')
        {
            return 5;
        }
        else if(ch=='X')
        {
            return 10;
        }
        else if(ch=='L')
        {
            return 50;
        }
        else if(ch=='C')
        {
            return 100;
        }
        else if(ch=='D')
        {
            return 500;
        }
        else if(ch=='M')
        {
            return 1000;
        }
        
        return -1;
    }
    
    
    
    int romanToInt(string s) {
        
        int n = s.size();
        int ans=0;
        
        for(int i=0;i<n;i++)
        {
            if(i != n-1 && convert(s[i]) < convert(s[i+1]))
            {
                ans = ans - convert(s[i]);
            }
            else
            {
                ans = ans + convert(s[i]);
            }
        }
        
        return ans;
    }
};