class Solution {
public:
    
    int countDig(int digit)
    {
        int cnt=0;
        
        while(digit > 0)
        {
            digit = digit/10;
            cnt++;
        }
        
        return cnt;
    }
    
    void dfs(int curr_digit,int n,int k,vector<int> & ans)
    {
        if(countDig(curr_digit)==n)
        {
            ans.push_back(curr_digit);
            return ;
        }
        
        for(int i=0;i<10;i++)
        {
            int last_digit = curr_digit%10;
            if(abs(last_digit-i)==k)
            {
                dfs(curr_digit*10+i,n,k,ans);
            }
        }
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        
         vector<int>ans;
        
          for(int i=1;i<10;i++)
          {
              dfs(i,n,k,ans);
          }
        
          return ans;
    }
};