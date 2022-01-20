class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        
        int start=0,end=0;
        double sum=0.0;
        double ans=(double)(INT_MIN);
        
        while(end < nums.size())
        {
            sum += nums[end];
            if(end-start+1 < k)
            {
                end++;
                continue;
            }
            
            if(end-start+1 == k)
            {
                double avg = sum/k;
                ans = max(avg,ans);
                //cout<<ans<<endl;
                end++;
                sum -= nums[start];
                start++;
            }
        }
        return ans;
    }
};