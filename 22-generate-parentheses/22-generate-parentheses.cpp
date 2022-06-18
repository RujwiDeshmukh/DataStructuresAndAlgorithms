class Solution {
public:
    
    void combinations(string temp,vector<string>& ans,int open,int close)
    {
        if(open==0 && close==0)
        {
            ans.push_back(temp);
            return ;
        }
        
        if(open>0) combinations(temp+"(",ans,open-1,close);
        if(open<close) combinations(temp+")",ans,open,close-1);
        
    }
    
    vector<string> generateParenthesis(int n) {
        
        vector<string>ans;
        combinations("",ans,n,n);
        return ans;
    }
};