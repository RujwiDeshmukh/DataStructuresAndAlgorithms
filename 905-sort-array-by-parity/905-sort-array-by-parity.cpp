class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        
        //traversing to swap the numbers present on the even indices
        int even=0;
        //traversing all the indices of the array i.e. curr
        int curr=0;
        
        while(curr < nums.size())
        {
            if(nums[curr]%2 == 0)
            {
                swap(nums[even],nums[curr]);
                even++;
            }
            
            curr++;
        }
        
        return nums;
    }
};