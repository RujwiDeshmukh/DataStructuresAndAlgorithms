class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        
        //two pointers approach to calculate the pairs
        //to implement this approach we need to sort the array
        int i=0;
        int j=nums.size()-1;
        int count=0;
        sort(nums.begin(),nums.end());
        
        while(i<j)
        {
            int sum = nums[i]+nums[j];
            
            if(sum==k)
            {
                i++;
                j--;
                count++;
            }
            else if(sum > k)
            {
                j--;
            }
            else
            {
                i++;
            }
        }
        
        return count;
    }
};