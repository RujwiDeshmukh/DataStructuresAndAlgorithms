class Solution {
public:
    
    bool isCyclic(vector<int>adj[],int curr,unordered_set<int>& vis,unordered_set<int>& dfs)
    {
        vis.insert(curr);
        dfs.insert(curr);
        
        for(auto neigh : adj[curr])
        {
        
        if(vis.find(neigh)==vis.end())
        {
            //we are returning from here bcoz we are supposed to return
            //from that point where we cycle is detected rather than exploring a
            //all the ways
            if(isCyclic(adj,neigh,vis,dfs))
            {
                return true;
            }
        }
            
            else if(dfs.find(neigh) != dfs.end())
            {
                return true;
            }
            
        }
        
        dfs.erase(curr);
        return false;
        
    }
    
    bool canFinish(int n, vector<vector<int>>& edges) {
        
        vector<int>adj[n];
        
        //graph created 
        for(int i=0;i<edges.size();i++)
        {
            vector<int>temp = edges[i];
            
            adj[temp[1]].push_back(temp[0]);
        }
        
        unordered_set<int>vis;
        unordered_set<int>dfs;
        
        for(int i=0;i<n;i++)
        {
            if(vis.find(i)==vis.end())
            {
                if(isCyclic(adj,i,vis,dfs))
                {
                    return false;
                }
            }
        }
        
        return true;
        
    }
};