class Solution {
public:
    
    void combinations(vector<vector<int>>& res, vector<int>& temp,int ind,int n,int k)
    {
        if(temp.size() == k)
        {
            res.push_back(temp);
            return;
        }
        
        for(int i=ind;i<n;i++)
        {
            temp.push_back(i+1);
            combinations(res,temp,i+1,n,k);
            temp.pop_back();
         }
    }
    
   // https://leetcode.com/problems/combinations/discuss/1586007/Two-Approach-Recursive-and-Iterative-C%2B%2B
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>res;
        vector<int>temp;
        if(n<k)   {      return res;  }   
        combinations(res,temp,0,n,k);     
        return res;
    }
};