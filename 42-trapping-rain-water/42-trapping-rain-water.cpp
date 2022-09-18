class Solution {
public:
    int trap(vector<int>& arr) {
        
        int n = arr.size();
        int left=0;
        int right=n-1;
        int ans=0;
        int leftMax=0, rightMax=0;
        
        while(left<=right)
        {
            if(arr[left] <= arr[right])
            {             
                 if(arr[left] >= leftMax)
                 {
                     leftMax = arr[left];
                 }
                else
                {
                    ans += leftMax - arr[left];
                }
                
                left++;
            }
            else // (arr[left] > arr[right])
            {
                if(arr[right] > rightMax)
                {
                    rightMax = arr[right];
                }
                else
                {
                    ans += rightMax - arr[right];
                }
                
                right--;
            }
        }
        
        return ans;
    }
};