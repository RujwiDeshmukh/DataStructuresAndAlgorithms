class Solution {
public:
    
    //here we cannot pass vector as reference as it the vector of list
bool isBipartite(vector<int> dislikes[],vector<int>& color,int node,int currColor)
    {
        if(color[node]!=-1)
        {
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
   //  cout<<dislikes[node]<<endl;
      for(auto neigh : dislikes[node])
      {
          if(isBipartite(dislikes,color,neigh,1-currColor)==false)
          {
              return false;
          }
      }
    
      return true;
    
    }
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        
        vector<int>color(n+1,-1);
        vector<int>graph[n+1];
        
        for(int i=0;i<dislikes.size();i++)
        {
            int src = dislikes[i][0];
            int dest = dislikes[i][1];
            
            graph[src].push_back(dest);
            graph[dest].push_back(src);
        }
        
        for(int i=1;i<=n;i++)
        {
            if(color[i]==-1)
            {
              if(isBipartite(graph,color,i,0)==false)
              {
                  return false;
              }
            }
        }
        
        return true;
    }
};