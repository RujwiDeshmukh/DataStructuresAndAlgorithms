class Solution {
public:
    
void generateSubsets(int idx,vector<int>& nums,vector<int>& res,vector<vector<int>>& ans)
    {
            if(idx >= nums.size())
            {
                ans.push_back(res);
                return ;
            }
       
            //notConsider
       generateSubsets(idx+1,nums,res,ans);
       res.push_back(nums[idx]);
       generateSubsets(idx+1,nums,res,ans);
       res.pop_back();
    
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>res;
        generateSubsets(0,nums,res,ans);
        return ans;
    }
};