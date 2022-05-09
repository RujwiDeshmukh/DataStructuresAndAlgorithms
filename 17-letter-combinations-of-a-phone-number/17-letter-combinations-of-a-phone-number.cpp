class Solution {
public:
    
    string calculateValue(char ch)
    {
        if(ch=='2')
        {
            return "abc";
        }
        else if(ch=='3')
        {
            return "def";
        }
        else if(ch=='4')
        {
            return "ghi";
        }
        else if(ch=='5')
        {
            return "jkl";
        }
        else if(ch=='6')
        {
            return "mno";
        }
        else if(ch=='7')
        {
            return "pqrs";
        }
        else if(ch=='8')
        {
            return "tuv";
        }
        else if(ch=='9')
        {
            return "wxyz";
        }
        
        return " ";
    }
    
    void combinations(string temp,int index,string digits,vector<string>& ans)
    {
        if(index >= digits.size())
        {
            ans.push_back(temp);
            return ;
        }
        
        string st = calculateValue(digits[index]);
        
        
        for(int i=0;i<st.length();i++)
        {
            temp.push_back(st[i]);
            combinations(temp,index+1,digits,ans);
            temp.pop_back();
        }
        
    }
    
    vector<string> letterCombinations(string digits) {
     
        vector<string>ans;
        if(digits.size() <= 0)
        {
            return ans;
        }
        
        combinations("",0,digits,ans);
        
        return ans;
    }
};