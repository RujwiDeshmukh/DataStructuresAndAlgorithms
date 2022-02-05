// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        // your code here
        
        int start=0;
        int end=0;
        deque<int>dq;
        vector<int>ans;
        
        while(end<n)
        {
            //not if as we dont at any how many smaller elements exist
            while(!dq.empty() && arr[end]>dq.back())
            {
                dq.pop_back();
            }
            
            dq.push_back(arr[end]);
            
            if(end-start+1<k)
            {
                end++;
            }
            //we are maintaing the dequeue always in decreasing order
            //as in every window we want to find largest element
            
            else if(end-start+1==k)
            {
                //perform operation as window size is encountered
                ans.push_back(dq.front());
                
                if(dq.front()==arr[start])
                {
                    dq.pop_front();
                }
                
                start++;
                end++;
            }
        }
        
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