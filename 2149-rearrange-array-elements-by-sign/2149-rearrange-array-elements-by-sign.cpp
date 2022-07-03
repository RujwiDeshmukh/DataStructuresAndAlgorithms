class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
        int n = nums.size();
        
        int idxneg = 1;
        int idxpos = 0;
        
        vector<int>res(n,0);
        
        for(int i=0;i<n;i++)
        {
            if(nums[i] < 0)
            {
                res[idxneg] = nums[i];
                idxneg+=2;
            }
            else if(nums[i] > 0)
            {
                res[idxpos] = nums[i];
                idxpos+=2;
            }
        }
        return res;
    }
};