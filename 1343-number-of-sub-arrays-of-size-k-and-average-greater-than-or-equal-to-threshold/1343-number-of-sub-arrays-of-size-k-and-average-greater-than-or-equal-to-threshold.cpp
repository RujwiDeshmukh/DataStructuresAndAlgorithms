class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        
        int start=0, end=0;
        int sum=0;
        int ans=0;
        
        while(end<arr.size())
        {
            sum += arr[end];
            if(end-start+1 < k)
            {
                end++;
                continue;
            }
            
            if(end-start+1==k)
            {
                int avg = sum/k;
                if(avg >= threshold)
                {
                    cout<<avg<<endl;
                    ans++;
                }
                sum -= arr[start];
                start++;
                end++;
            }
        }
        return ans;
    }
};