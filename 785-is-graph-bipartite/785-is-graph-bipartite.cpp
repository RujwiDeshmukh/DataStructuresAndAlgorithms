class Solution {
public:
    
    bool dfs(int node,vector<vector<int>>&graph,vector<int>& color,int currColor)
    {
        if(color[node]!=-1)
        {
            //return color[node]==currColor;
            
            if(color[node]!=currColor)
            {
                return false;
            }
            else
            {
                return true;
            }
        }
       
        color[node]=currColor;
        for(auto neigh : graph[node])
        {
            if(dfs(neigh,graph,color,1-currColor)==false)
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
               cout<<"Color : "<<color[i]<<endl;
              if(dfs(i,graph,color,0)==false)
              {
                  return false;
              }
           }
        }
        
        return true;
    }
};