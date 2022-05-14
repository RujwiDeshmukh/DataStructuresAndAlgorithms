class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        vector<int>sorted(nums.begin(), nums.end());
        sort(sorted.begin(),sorted.end());
        int size = sorted.size();
        cout<<size<<endl;
        int n = nums.size();
        int i=0;
        int j= n-1;
        
        while(i<n && nums[i]==sorted[i])
        {
            i++;
        }
        
        //j should be greater than i as 
        //second loop hole should be after 2nd loop hole
        while(j>i && nums[j]==sorted[j])
        {
            j--;
        }
        
        cout<<i<<endl;
        cout<<j<<endl;
        
        return j-i+1;
    }
};