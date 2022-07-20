class Solution {
public:
    
    bool bipartiteBfs(int node,vector<vector<int>>& graph,vector<int>& color)
    {      
        for(auto neigh : graph[node])
        {
            if(color[neigh]==-1)
            {
                color[neigh] = 1-color[node];
                if(!bipartiteBfs(neigh,graph,color))
                {
                    return false;
                }
            }
            else if(color[neigh]==color[node])
            {
                return false;
            }
        }
        
        return true;
    }

    
    bool isBipartite(vector<vector<int>>& graph) {
        
        vector<int>color(graph.size(),-1);
        
        for(int i=0;i<graph.size();i++)
        {
            if(color[i]==-1)
            {
                color[i]=1;
                if(!bipartiteBfs(i,graph,color))
                {
                    return false;
                }
            }
        }
        return true;
    }
};