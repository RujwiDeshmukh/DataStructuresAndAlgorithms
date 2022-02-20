// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to count paths between two vertices in a directed graph.
    void countPath(vector<int> adj[],int src,int dest,vector<int>& vis,
    int &paths)
    {
        vis[src]=1;
        //base condition if we reached to our destination
        if(src==dest)
        {
            paths++;
           // cout<<paths<<endl;
           //as we are returning from here
           //we have to first unmark the last node 
           //and then have to return as we wont move upto the down
            vis[src]=0;
            return ;
        }
        
        //if destination is not yet found then traverse the adhacent nodes
        for(auto neigh : adj[src])
        {
            if(vis[neigh]==0)
            {
                countPath(adj,neigh,dest,vis,paths);
            }
            
            //this will aslo work
            // vis[src]=0;
        }
        
    
         vis[src]=0;
        
    }
    
    //TC--->O(V!)
    //SC--->O(1)
    
    
    int countPaths(int V, vector<int> adj[], int source, int destination) {
        // Code here
        int paths=0;
        vector<int>vis(V,0);
        countPath(adj,source,destination,vis,paths);
        return paths;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // adj[v].push_back(u);
        }
        int source, destination;
        cin >> source >> destination;
        Solution obj;
        cout << obj.countPaths(V, adj, source, destination) << endl;
    }
    return 0;
}  // } Driver Code Ends