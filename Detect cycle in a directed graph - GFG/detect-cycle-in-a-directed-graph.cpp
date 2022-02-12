// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        //topological sort we are applying here
        //if totgological sort is generated then there is no cycle
        //and all vertices can be visited
        
        //Using BFS
        queue<int>q;
        vector<int>deg(V,0);
        
        //calculate indegree
        for(int i=0;i<V;i++)
        {
            //pointing to neighbour
            for(auto it : adj[i])
            {
                deg[it]++;
            }
        }
        
        
        for(int i=0;i<V;i++)
        {
            if(deg[i]==0)
            {
                q.push(i);
            }
        }
        
        int count = 0;
        
        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
            count++;
            
            for(auto neigh : adj[node])
            {
                 if(deg[neigh]>0)
                 {
                     deg[neigh]--;
                 }
                 
                 if(deg[neigh]==0)
                 {
                     q.push(neigh);
                 }
            }
        }
        
        //cout<<count<<endl;
        
        if(count==V)
        {
            return false;
        }
        return true;
        
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