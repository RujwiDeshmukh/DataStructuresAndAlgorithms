// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    
    void dfs(vector<int>adj[],int node,vector<int>& vis)
    {
          vis[node]=1;
          
          for(auto neigh : adj[node])
          {
              if(!vis[neigh])
              {
                  dfs(adj,neigh,vis);
              }
          }
    }
    
    //Time Complexity => O(V(V+E)
    //As we are visiting all the nodes 
    //all the edges
    
    //Function to find a Mother Vertex in the Graph.
	int findMotherVertex(int V, vector<int>adj[])
	{
	    // Code here
	    vector<int>vis(V,0);
	    int flag=0;
	    int ans=0;
	    for(int i=0;i<V;i++)
	    {
	        if(vis[i]==0)
	        {
	            vector<int>visNode(V,0);
	            dfs(adj,i,visNode);
	            
	            for(int j=0;j<V;j++)
	            {
	                if(visNode[j]==0)
	                {
	                    flag=1;
	                }
	            }
	            
	            if(!flag)
	            {
	                ans=i;
	                return ans;
	            }
	        }
	    }
	    
	    return -1;
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends