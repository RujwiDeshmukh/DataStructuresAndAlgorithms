class Solution {
public:
    int longestMountain(vector<int>& arr) {
        
        int n = arr.size();
        int count=0;
        
        int i=1;
        
        while(i<n)
        {
            while(i<n && arr[i]==arr[i-1])
            {
                i++;
            }
            
            int up=0;
         
            //increasing condition
            while(i<n && arr[i]>arr[i-1])
            {
                i++;
                up++;
            }
            
            int down=0;
            //decreasing condition
            while(i<n && arr[i-1]>arr[i])
            {
                i++;
                down++;
            }
            
            if(up>0 && down>0)
            {
                count = max(count,up+down+1);
            }
        }
        return count;
    }
};