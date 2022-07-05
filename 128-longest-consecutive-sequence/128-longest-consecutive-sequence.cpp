class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        //https://leetcode.com/problems/longest-consecutive-sequence/discuss/41060/A-simple-   C%2B%2Bsolution-using-unordered_set.And-simple-consideration-about-this-problem
        
        if(nums.empty())
        {
            return 0;
        }
        
        unordered_set<int>st(nums.begin(),nums.end());
        int ans=1;
        
        for(auto num : nums)
        {
            if(st.find(num) == st.end())
            {
                continue;
            }
            
            st.erase(num);
            
            int prev = num-1;
            int next = num+1;
            
            while(st.find(prev) != st.end())
            {
                st.erase(prev);
                prev--;
            }
            
            while(st.find(next) != st.end())
            {
                st.erase(next);
                next++;
            }
            
            ans = max(ans,next-prev-1);
        }
        return ans;
    }
};