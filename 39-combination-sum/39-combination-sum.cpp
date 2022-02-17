class Solution {
public:
    
    void totalWays(vector<int>& candidates,int index,int target,vector<vector<int>>& dp,vector<int>& temp)
    {
        if(target==0)
        {
            dp.push_back(temp);
            return;
        }
        
        if(index >= candidates.size())
        {
            return ;
        }
        
        if(target >= candidates[index])
        {
            temp.push_back(candidates[index]);
            totalWays(candidates,index,target-candidates[index],dp,temp);
            temp.pop_back();
        }
        
        totalWays(candidates,index+1,target,dp,temp);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>dp;
        vector<int>temp;
        totalWays(candidates,0,target,dp,temp);   
        return dp;
    }
};