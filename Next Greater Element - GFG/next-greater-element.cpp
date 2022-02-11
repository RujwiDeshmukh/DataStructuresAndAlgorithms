// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        
        stack<int>st;
        vector<long long> nge(n,0);
        
        for(int i=0;i<n;i++)
        {
           while(!st.empty() && arr[i] > arr[st.top()])
           {
               nge[st.top()] = arr[i];
               st.pop();   
           }
           //pushing index as we have to keep track of elements of array
           //in nge array
           st.push(i);
        }
        
        while(!st.empty())
        {
            nge[st.top()] = -1;
            st.pop();
        }
        
        return nge;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}  // } Driver Code Ends