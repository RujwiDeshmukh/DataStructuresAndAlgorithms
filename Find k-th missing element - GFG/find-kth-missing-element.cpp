// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    int MissingNumber(int a[], int b[], int k, int n, int m)
    {
        // Complete the function
        int count=0;
          
          unordered_set<int>st;
          
          for(int i=0;i<m;i++)
          {
              st.insert(b[i]);
          }
          
          for(int i=0;i<n;i++)
          {
              if(st.find(a[i]) == st.end())
              {
                   count++;  
              }
              
              if(count==k)
              {
                  return a[i];
              }
          }
          
          return -1;
    }
};

// { Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n,m,k;
        cin>>n>>m>>k;
        int a[n],b[m];
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<m;i++)
            cin>>b[i];
        Solution ob;
        cout << ob.MissingNumber(a, b, k, n, m)<<endl;

    }
    return 0;
}
  // } Driver Code Ends