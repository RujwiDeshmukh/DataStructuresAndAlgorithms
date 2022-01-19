// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        // Code here.
        
        unordered_map<int,int>mp;
        
        for(int i=0;i<nums.size();i++)
        {
            
            int currVal = nums[i];
            int currRem = (((nums[i]%k)+k)%k);
            mp[currRem]++;
        }
        
        for(auto m : mp)
        {
            if(m.first==0)
            {
                if((m.second)%2 != 0)
                {
                    return false;
                }
            }
            else if(mp.find(k-m.first) == mp.end())
            {
                return false;
            }
            else if(mp[k-m.first] != m.second)
            {
                return false;
            }
        }
        
        return true;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}  // } Driver Code Ends