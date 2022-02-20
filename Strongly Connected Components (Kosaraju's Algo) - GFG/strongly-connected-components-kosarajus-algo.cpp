// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	
	void dfs(int node,vector<int> adj[],vector<int>& vis,vector<int>& recurDfs)
	{
	    vis[node]=1;
	    
	    for(auto neigh : adj[node])
	    {
	        if(!vis[neigh])
	        {
	            dfs(neigh,adj,vis,recurDfs);
	        }
	    }
	    
	    recurDfs.push_back(node);
	}
	
	
	void dfsRev(int node,vector<int> adj[],vector<int>& vis)
	{
	    //cout<<node<<" ";
	    vis[node]=1;
	    
	    for(auto neigh : adj[node])
	    {
	        if(!vis[neigh])
	        {
	            dfsRev(neigh,adj,vis);
	        }
	    }
	    
	}
	
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        //code here
        vector<int>vis(V,0);
        vector<int>recurDfs;
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                dfs(i,adj,vis,recurDfs);
            }
        }
        
        reverse(recurDfs.begin(),recurDfs.end());
        
        vector<int>transpose[V];
        
        for(int i=0;i<V;i++)
        {
            vis[i]=0;
            
            //it is child
            //i is parent
            for(auto it : adj[i])
            {
                transpose[it].push_back(i);
                // it is parent and i is child
            }
        }
        int count=0;
        
        for(int i=0;i<recurDfs.size();i++)
        {
            if(!vis[recurDfs[i]])
            {
               // cout<<"SSC : ";
                dfsRev(recurDfs[i],transpose,vis);
                count++;
               // cout<<endl;
            }
        }
        return count;
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends