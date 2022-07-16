class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int sum=0;
        int max_sum = INT_MIN;
        int s=0;
        int e;
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] < sum+nums[i])
            {
                sum = sum+nums[i];
            }
            else
            {
                sum = nums[i];
                s=i;
            }
            
            if(sum > max_sum)
            {
                max_sum = sum;
                e=i;
            }
        }
        
        cout<<"start : "<<s<<endl;
        cout<<"end : "<<e<<endl;
         
        return max_sum;
    }
};