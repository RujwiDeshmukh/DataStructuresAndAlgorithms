class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int>s(nums.begin(),nums.end());
        int longest=0;
       // https://leetcode.com/problems/longest-consecutive-sequence/discuss/41060/A-simple-C%2B%2Bsolution-using-unordered_set.And-simple-consideration-about-this-problem
        for(auto num : nums)
        {
            int curr_longest=1;
            // we are finding the consecutive smaller and greater elements
            //for each element present in an array
            for(int j=1;s.count(num-j)!=0;j++)
            {
                s.erase(num-j);
                curr_longest++;
            }
            
            for(int j=1;s.count(num+j)!=0;j++)
            {
                s.erase(num+j);
                curr_longest++;
            }
            
           longest = max(curr_longest,longest);
        }
        
        return longest;
    }
};