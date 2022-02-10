class Solution {
public:
    
    
    bool isCyclic(vector<int>adj[],int n,int curr,unordered_set<int>&vis, unordered_set<int>& dfs, vector<int>& traversal)
    {
        vis.insert(curr);
        dfs.insert(curr);
        
        for(auto neigh : adj[curr])
        {
            if(vis.find(neigh) == vis.end())
            {
                if(isCyclic(adj,n,neigh,vis,dfs,traversal))
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
        traversal.push_back(curr);
        return false;
        
    }
    
    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        
        vector<int>adj[n];
        
        for(int i=0;i<edges.size();i++)
        {
            vector<int>temp = edges[i];
            
            adj[temp[1]].push_back(temp[0]);
        }
        
        unordered_set<int>vis;
        unordered_set<int>dfs;
        vector<int>traversal;
        
        for(int i=0;i<n;i++)
        {
            if(vis.find(i) != vis.end())
            {
                continue;
            }
            
            if(isCyclic(adj,n,i,vis,dfs,traversal))
            {
                vector<int> temp;
                return temp;
            }
        }
        
         reverse(traversal.begin(),traversal.end());
        return traversal;
    }
};