class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        
        int sum=0;
        int maxSum=0;
        int end=0, start=0;
        int n = nums.size();
        unordered_set<int>st;
        
        while(end < n)
        {
           // for example like 5 6 7 8 7 
            //now we have to remove elements till 7 starting from 5
            //here we are using while loop because we dont know the position of
            //the repeated elements
            while(st.find(nums[end]) != st.end())
            {
                st.erase(nums[start]);
                sum = sum - nums[start];
                start++;
            }
            
            st.insert(nums[end]);
            sum += nums[end];
            maxSum = max(maxSum,sum);
            
            end++;
        }
        
        return maxSum;
    }
};