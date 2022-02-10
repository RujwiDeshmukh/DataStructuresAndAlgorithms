// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  
    bool checkCycle(int currentIndex,unordered_set<int>& vis,unordered_set<int>& st,
    vector<int> adj[])
    {
          vis.insert(currentIndex);
          st.insert(currentIndex);
          
          for(auto neigh : adj[currentIndex])
          {
              if(vis.find(neigh) == vis.end())
              {
                 if(checkCycle(neigh,vis,st,adj))
                 {
                     return true;
                 }
              }
              
              else if(st.find(neigh) != st.end())
              {
                  return true;
              }
          }
          
          st.erase(currentIndex);
          return false;
    }
  
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        
        unordered_set<int>st;
        unordered_set<int>vis;
         
         for(int i=0;i<V;i++)
         {
             if(vis.find(i) == vis.end())
             {
                 if(checkCycle(i, vis, st, adj))
                 {
                     return true;
                 }
             }
         }
         
         return false;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends