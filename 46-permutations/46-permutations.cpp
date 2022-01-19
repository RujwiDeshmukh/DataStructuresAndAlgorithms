class Solution {
public:
    
    void recurPermute(vector<int> &ds, vector<int> &nums, vector<vector<int>> &ans, int        freq[])
    {
        //base condition 
        if(ds.size()>=nums.size())
        {
            ans.push_back(ds);
            return;
        }
        
        for(int i=0;i<nums.size();i++)
        {
            if(!freq[i])
            {
                freq[i]=true;
                ds.push_back(nums[i]);
                recurPermute(ds, nums, ans, freq);
                //unmark it in frequency array
                freq[i]=false;
                //we have to remove the element as we are ds by refrence
                ds.pop_back();
            }
        }
    }
    
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds;
        int freq[nums.size()];
        for(int i=0;i<nums.size();i++)
        {
            freq[i]=0;
        }
        recurPermute(ds, nums, ans, freq);
        return ans;
    }
};