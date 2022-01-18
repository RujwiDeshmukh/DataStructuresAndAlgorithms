// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool isProduct(int arr[], int n, long long x) {
        
        //as in constraint it is given that arr[i] can be zero so have to h\
        //handle that case
        
        if(n<2)
        {
            return false;
        }
        
        unordered_set<int>st;
        
        
        for(int i=0;i<n;i++)
        {
            if(arr[i]==0)
            {
                //product of 0 with any element is zero
                if(x==0)
                {
                    return true;
                }
                else
                {
                    continue;
                }
            }
            else
            {
                if((x%arr[i])==0)
                {
                    if(st.find((x/arr[i])) != st.end())
                    {
                        return true;
                    }
                    
                    //adding element only it is divisible by that number
                    //there is no need to insert elements that are not divisible
                    st.insert(arr[i]);
                }
                
            }
        }
        
        return false;
    }
};

// { Driver Code Starts.

int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        int n;
        long long x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.isProduct(arr, n, x);
        cout << (ans ? "Yes\n" : "No\n");
    }
    return 0;
}  // } Driver Code Ends