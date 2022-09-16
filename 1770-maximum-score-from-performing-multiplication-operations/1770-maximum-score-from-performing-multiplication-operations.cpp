class Solution {
public:
    
   // https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations/discuss/1078881/C%2B%2B-DP-(SIMPLEST-TO-UNDERSTAND)-greater-Recursive-to-Memorisation-greater-Complete-EXPLANATION
    
    //https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations/discuss/1075469/JavaC%2B%2BPython-3-Top-Down-DP-O(m2)-Clean-and-Concise
    
   // https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations/discuss/2156486/Greedy-Failed-From-Level-Zero-or-Beginner-Friendly-or-Fully-Explained-or-Python-or-C
    
    int maxScore(int ind,int l,int r,vector<int>& nums,vector<int>& muls, vector<vector<int>> & dp)
    {
         if(ind>=muls.size())
         {
             return 0;
         }
        
         if(dp[ind][l] != INT_MIN)
         {
             return dp[ind][l];
         }
        
         int left = nums[l]*muls[ind]+maxScore(ind+1,l+1,r,nums,muls,dp);
         int right = nums[r]*muls[ind]+maxScore(ind+1,l,r-1,nums,muls,dp);
        
        //left pointer and right pointer can go upto n
        //combinally they form n states
        //we can fill ythe states like for l left elements 
        //value can be this or that
        
        return dp[ind][l]=max(left,right);
    }
    
    int maximumScore(vector<int>& nums, vector<int>& muls) {
        
        //should not initialize the vector with -1
        //if answer is -1 then it will work as recursion so TLE
        
        vector<vector<int>>dp(muls.size()+1,vector<int>(muls.size()+1,INT_MIN));
        
        return maxScore(0,0,nums.size()-1,nums,muls,dp);
    }
};