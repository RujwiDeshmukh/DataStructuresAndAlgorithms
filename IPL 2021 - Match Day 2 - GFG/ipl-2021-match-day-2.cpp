// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> nums, int n, int k) {
        // your code here
        
        //it is the same the same problem as sliding window maximum
        //here trick is we are maintaining the largest element for that 
        //window in front the queue , removing the elements such that
        //when the greater element encounters remove the smaller elements
        //using deque as it allows opeartion from both front and back side
        /*deque<int>dq;
        vector<int>ans;
        
        // we are storing indexes in the array
        for(int i=0;i<k;i++)
        {
             if(!dq.empty()  && (arr[i]>arr[dq.back()]))  
             {
                 dq.pop_back();
                 //removing element form back side
             }
             dq.push_back(i);
        }
        
        //window size is reached soperforming operation
        
        int val = dq.front();
        ans.push_back(arr[val]);
        
        for(int i=k;i<arr.size();i++)
        {
            //now we want to remove the starting element from array
            while(!dq.empty() && dq.front() <= i-k)
            {
                //sliding window from starting
                dq.pop_front();
            }
            
            while(!dq.empty() && arr[i]>arr[dq.back()])
            {
                dq.pop_back();
            }
            
            dq.push_back(i);
            
        int val = dq.front();
        ans.push_back(arr[val]);
        }
        return ans;*/
        
         deque<int>q;
        vector<int>ans;
        
         for(int i=0;i<k;i++)
        {
            while(!q.empty() &&  nums[i]>nums[q.back()])
            {
                q.pop_back();
            }
            q.push_back(i);
        }
        
        for(int i=k;i<nums.size();i++)
        {
           int val = q.front();
           ans.push_back(nums[val]);
          
            while(!q.empty() && q.front() <= i-k)
            {
                q.pop_front();
            }
            
            while(!q.empty() &&  nums[i]>nums[q.back()])
            {
                q.pop_back();
            }
            
            q.push_back(i);
        }
        
        int val = q.front();
        ans.push_back(nums[val]);
        
        return ans;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}  // } Driver Code Ends