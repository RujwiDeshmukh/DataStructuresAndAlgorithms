class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
     
         //n is vertices here, there can nodes but zero paths so have
        //to check that condition
        
        int p = paths.size();
        vector<int>ans(n,1);
        vector<int>graph[n+1];
        vector<int>result(n,-1);
        
        if(p==0)
        {
            return ans;
        }
        
        //creating the bidirectional graph
        for(int i=0;i<paths.size();i++)
        {
            int src = paths[i][0];
            int dest = paths[i][1];
            
            graph[src].push_back(dest);
            graph[dest].push_back(src);
        }
        
        
        //now we have to color all the n nodes, so iterate over this nodes
        
        for(int i=1;i<=n;i++)
        {
            //initially all the colors are available so we are declaring the color vector here
            vector<int>color(5,0); //as the color value 1 to n
            
        //check for all the adjacent nodes of that particular if it has already
        //colored if yes then eliminating that colors which are already used
            //this is used for creating the set of avialable colors
            for(int j : graph[i])
            {
                if(result[j-1] != -1)
                {
                    color[result[j-1]]=1;
                }
            }
            
            for(int k=1;k<=4;k++)
            {
                if(color[k]==0)
                {
                    result[i-1]=k;
                    break;
                }
            }
        }
        
        return result;
    }
};