class Solution {
public:
    
   void generatePermutations(vector<int> nums, vector<vector<int>>& output, int idx) {
        if (idx >= size(nums)) {
            output.push_back(nums);
            return;
        }
        for (int i = idx; i < nums.size(); ++i) {
            if (i != idx && nums[i] == nums[idx]) continue;
            swap(nums[i], nums[idx]);
            generatePermutations(nums, output, idx + 1);
            //swap(nums[i],nums[idx]);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> output;
        sort(nums.begin(), nums.end());
        generatePermutations(nums, output, 0);
        return output;
    }
};