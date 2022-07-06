class Solution {
public:
    string convert(string s, int numRows) {
        
        
        int n = s.size();
        vector<string>tmp(numRows);
        bool down=false;
        int j=0;
        string ans="";
        
        if(numRows == 1)
        {
            return s;
        }
        
        for(int i=0;i<n;i++)
        {
            tmp[j] += s[i];
            if(j==numRows-1)
            {
               down=false;   
            }
            else if(j==0)
            {
                down=true;
            }
            if(down==true)
            {
                j++;
            }
            else
            {
                j--;
            }
        }
        
        for(auto i : tmp)
        {
            ans += i;
        }
        
        return ans;
    }
};