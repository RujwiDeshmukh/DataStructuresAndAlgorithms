class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector<vector<int>>res;
        
        if(nums.empty())
        {
            return res;
        }
        
        int n = nums.size();
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int targetSum = target-(nums[i]+nums[j]);
                
                int left = j+1;
                int right = n-1;
                
                
                while(left<right)
                {
                    int twoSum = nums[left]+nums[right];
                    
                    if(twoSum < targetSum)
                    {
                        left++;
                    }
                    else if(twoSum > targetSum)
                    {
                        right--;
                    }
                    else
                    {
                        vector<int>ans(4,0);
                        ans[0] = nums[i];
                        ans[1] = nums[j];
                        ans[2] = nums[left];
                        ans[3] = nums[right];
                        
                        res.push_back(ans);
                    
                    //Processing the duplicates of number 3
                    while(left < right && nums[left]==ans[2])
                    {
                        left++;
                    }
                    
                    while(left < right && nums[right]==ans[3])
                    {
                        right--;
                    }
                        
                    }
                }
             
                //to handle the dupliactes
                //here were are using j+1 as for loop will also increment 
                //one time again
            while(j+1<n && nums[j+1]==nums[j])
            {
                j++;
            }
                
            }
            
            while(i+1<n && nums[i+1]==nums[i])
            {
                i++;
            }
        }
        
        return res;
    }
};