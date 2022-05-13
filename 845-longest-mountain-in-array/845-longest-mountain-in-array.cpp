class Solution {
public:
    int longestMountain(vector<int>& arr) {
        
        int n = arr.size();
        int ans=0;
        
        //0 and n-1 cannot be the peak element 
        //so we will start the loop from
        
        for(int i=1;i<=n-2;)
        {
            //find the peak element
            if(arr[i]>arr[i-1] && arr[i]>arr[i+1])
            {
                //peak element is found
                //find valley on the both sides of the peak element
                
                int j=i;
                //peak element is already counted
                int count=1;
                
                while(j>0 && arr[j]>arr[j-1])
                {
                     j--;
                    count++;
                }
                
                while(i<n-1 && arr[i]>arr[i+1])
                {
                    i++;
                    count++;
                }
                
                 ans = max(ans,count);
            }
            else
            {
                i++;
                //as we know that peak element will be found after one
                //mountain is over 
                //as peak element should have neighbours less than itself
                //until valley is encountering we cannot find such element 
                //so incrementing i wont effect
            }
            
        }
        
        return ans;
    }
};