class Solution {
public:
    
    void dfs(vector<int>graph[],vector<int>& vis,int node)
    {
        vis[node]=1;
        
        for(auto neigh : graph[node])
        {
            if(!vis[neigh])
            {
                dfs(graph,vis,neigh);
            }
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& edges) {
        
        //if we want our graph to be connected then
        //there must be n-1 edges present in the graph

        if(edges.size() < n-1)
        {
            return -1;
        }
        
        vector<int>vis(n,0);
        int components=0;
        
        vector<int>graph[n];
        
        for(int i=0;i<edges.size();i++)
        {
            int from = edges[i][0];
            int to = edges[i][1];
            
            graph[from].push_back(to);
            graph[to].push_back(from);
        }
        
        //now in our graph there are several components
        //that are disconnected from each other
        //if there are k such disconnected components then 
        //we will require k-1 edges to connect them all into one
        
        for(int i=0;i<n;i++)
        {
            if(vis[i]!=1)
            {
                components++;
                dfs(graph,vis,i);
            }
        }
        
        return components-1;
    }
};