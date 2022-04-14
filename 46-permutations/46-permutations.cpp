class Solution {
public:
    
    void recurPermutate(vector<int>& nums,int n,vector<int>& ds,vector<vector<int>>& ans, vector<int>& freq)
    {
        if(ds.size() >= n)
        {
            ans.push_back(ds);
            return;
        }
        
        //check for all the possibilities that we can pick
        
        for(int i=0;i<n;i++)
        {
            if(!freq[i])
            {
                //mark the index as visited or not from that we can infer if the element
                //of that same index will be picked or not next time
                freq[i]=1;
                ds.push_back(nums[i]);
                //n! complexity for generating all the permutations of the given array
                //O(n) complexity => for loop
                recurPermutate(nums,n,ds,ans,freq);
                //after the completion of the function call remove it from
                //data structure and unmark it as well
                ds.pop_back();
                freq[i]=0;
            }
        }
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
       vector<vector<int>>ans;
        int n = nums.size();
        vector<int>freq(n,0);
        vector<int>ds;
        recurPermutate(nums,n,ds,ans,freq);
        return ans;
        
    }
};