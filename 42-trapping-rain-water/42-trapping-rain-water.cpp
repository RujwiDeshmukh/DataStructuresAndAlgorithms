class Solution {
public:
    int trap(vector<int>& arr) {
        
        int n = arr.size();
        int totWater = 0;
        
        vector<int>leftMax(n,0), rightMax(n,0);
        
        leftMax[0] = arr[0];
        rightMax[n-1] = arr[n-1];
        
        for(int i=1;i<n;i++)
        {
            leftMax[i] = max(leftMax[i-1],arr[i]);
        }
        
        for(int i=n-2;i>=0;i--)
        {
            rightMax[i] = max(rightMax[i+1],arr[i]);
        }
        
          for(int i=0;i<n;i++)
          {
              totWater += min(leftMax[i],rightMax[i])-arr[i];
          }
        
        return totWater;
    }
};