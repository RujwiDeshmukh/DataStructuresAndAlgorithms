class Solution {
public:
    int longestMountain(vector<int>& arr) {
        
        int n = arr.size();
        vector<int>up(n,0);
        vector<int>down(n,0);
        int ans=0;
        
        for(int i=n-2;i>=0;i--)
        {
            if(arr[i]>arr[i+1])
            {
                down[i] = down[i+1]+1;
            }
        }
        
        for(int i=1;i<n;i++)
        {
            if(arr[i]>arr[i-1])
            {
                up[i] = up[i-1]+1;
            }
        }
        
        for(int i=0;i<n;i++)
        {
            if(up[i]&&down[i])//&& is used as it is mandatory that
                //both sides of the peak element should consist of valley
            {
                ans = max(ans,up[i]+down[i]+1);
            }
        }
        
        return ans;
    }
};